# VEX-V5-Tensorflow
This is a sample PROS (https://pros.cs.purdue.edu/) project with Tensorflow Lite support.

This project was designed to allow all competitors in the VEX robotics competitions to use machine learning inference on their robots.

It includes a subset of the TFLite Micro, flatbuffers, fixedpoint, ruy libraries, and a modified makefile/common.mk to compile them without the need for Bazel.

Looking forward to seeing amazing uses of this tool in future VEX competitions! We imagine Tensorflow to be usable for sensor fusion, SLAM, and more.

# Getting Started
This repository contains a prepared sample PROS project that includes Tensorflow and a MNIST sample model.

## Clone this project and edit it
This option is easier if you either did not make a project yet or have a somewhat simple project which can be tampered with. The current project will run a sample MNIST model and print a predicted digit based on the data it is given. If you do not want to do this, you can follow the steps in `update-tensorflow.md` to integrate it into an existing project.

To test the project, try to run the program and use the `pros terminal` command and you should see some numbers showing up every 5 seconds.

## Next steps
1. Train your own model, using Keras (for example https://colab.research.google.com/github/AviatorMoser/keras-mnist-tutorial/blob/master/MNIST%20in%20Keras.ipynb#scrollTo=LI2RmW7r87aW)
2. Convert your model to TFLite and upload it to Google Drive
```
import tensorflow as tf

from google.colab import drive
drive.mount('/content/drive')
tf.saved_model.save(model, "/content/drive/MyDrive/MNIST")

# Convert the model
converter = tf.lite.TFLiteConverter.from_saved_model("/content/drive/MyDrive/MNIST") # path to the SavedModel directory

# For now, it seems like quantization is not supported and might give errors
# converter.optimizations = [tf.lite.Optimize.OPTIMIZE_FOR_SIZE]
tflite_model = converter.convert()

# Save the model.
with open('/content/drive/MyDrive/MNIST/model.tflite', 'wb') as f:
  f.write(tflite_model)
```
3. Download the model to your machine
4. Convert the model to a serialized C++ array using a tool such as xxd using `xxd -i your_model.tflite > model_data.cc`
5. Change the `AI-model.cpp` file with your own model serialized in a C++ array.
  * Alter the `makeData()` function to use whatever you need it to (such as sensor inputs from your robot), and change the size of the `input_data[]` and `output_data[]` arrays as necessary for your inputs and outputs for the model.
  * Also change the `TFLiteTask()` function, such as the `delay(5000)` to use different time intervals, or any other changes.
