#include "header.hpp"

float input_data[784];
float output_data[10];

void makeData()
{
    //TODO: put stuff here, depending on the data you need for the input of your model
    for(int i = 0; i < 784; i++)
        input_data[i] = 0;
    for(int i = 1; i < 21; i ++)
        input_data[i] = 255, input_data[28 + i] = 255;
    for(int i = 1; i < 27; i ++)
        input_data[28*i + 13] = 255, input_data[28*i + 13] = 255;
    for(int i = 13; i < 26; i ++)
        input_data[28*26+i] = 255, input_data[28*27 + i] = 255;
}

inline void print_output_data(float* output) 
{
    cout << "data: ";
    for(int i = 0; i < 10; i++) 
        cout << fixed << setprecision(3) << output[i] << " ";
    memcpy(output_data, output, 10*sizeof(float));
    cout << "\n\n";
}

TfLiteStatus TFLiteTask() 
{
    tflite::MicroErrorReporter micro_error_reporter;

    //Allocate 4MB memory for the tensor arena.
    uint8_t* tensor_arena  = (uint8_t*)malloc(TENSOR_ARENA_SIZE);
    //cout << "memory allocation v1.1 " << *tensor_arena << "\n";

    const tflite::Model* model = tflite::GetModel(mnist_tflite);

    if (model->version() != TFLITE_SCHEMA_VERSION) 
    {
        TF_LITE_REPORT_ERROR(&micro_error_reporter,
                            "Model provided is schema version %d not equal "
                            "to supported version %d.\n",
                            model->version(), TFLITE_SCHEMA_VERSION);
        return kTfLiteError;
    }

    tflite::AllOpsResolver resolver;

    tflite::MicroInterpreter interpreter(
        model, resolver, 
        tensor_arena, TENSOR_ARENA_SIZE, &micro_error_reporter);
        
    TfLiteStatus allocate_status = interpreter.AllocateTensors();

    if (allocate_status != kTfLiteOk) 
    {
        TF_LITE_REPORT_ERROR(&micro_error_reporter, "Tensor allocation failed\n");
        return kTfLiteError;
    }

    while(true)
    {
        makeData();
        // Read data from robot data
        float* input = interpreter.typed_input_tensor<float>(0);
        for(int i = 0; i < 784; i ++)
            input[i] = input_data[i];
        TfLiteStatus invoke_status = interpreter.Invoke();
        if (invoke_status != kTfLiteOk) 
        {
            TF_LITE_REPORT_ERROR(&micro_error_reporter, "Invoke failed\n");
            return kTfLiteError;
        }

        // Print all of the output data
        printf("num_of_outputs: %d\n", interpreter.outputs_size());
        float* output = interpreter.typed_output_tensor<float>(0);
        print_output_data(output);
        cout << "\n\noutput end\n";
        delay(5000);
    }

    return kTfLiteOk;
}

void MLTask(void *param)
{
    printf("MLTask\n");
    TFLiteTask();
}