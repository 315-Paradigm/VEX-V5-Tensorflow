This document describes the tensorflow update procedure to integrate TFLite into an existing PROS project

## Follow these steps:
* Open your existing project or create a new one using PROS. You will next copy some libraries into the `/src` folder of your project, which is the folder referred to in future steps
* Get TFLite Micro
  * First, run this to clone TFLite to your machine `git clone https://github.com/tensorflow/tflite-micro.git`
  * Copy the folder `tensorflow` to your `/src` folder
  * From the folder `tensorflow`, delete the following folders (if they exist):
    * `/experimental`, `/python`, `/tools`
    * From the folder `/micro`, delete all subfolders except for `/kernels`, `/memory_planner`, and `/arena_allocator`
    * Also from the folder `/micro`, delete all files which end in `\_test.cc`
    * Also, repeat similar steps for the folder `/micro/kernels`, `/micro/memory\_planner`, and `/micro/arena\_allocator` (delete all subfolders and `\*\_test.cc` files) 
    - Delete `/micro/kernels/conv_test_common.cc` and `/micro/kernels/conv_test.h`
* Get FlatBuffers v2.0.5
  * First, run this to clone FlatBuffers to your machine `git clone https://github.com/google/flatbuffers.git`
  * Then, run the command `git checkout tags/v2.0.5` to switch to the right version
  * Copy the folder `flatbuffers/include/flatbuffers` to your `/src` folder
* Get FixedPoint
  * First, run this to clone FixedPoint to your machine `git clone https://github.com/google/gemmlowp.git`
  * Copy the folder `gemmlowp/fixedpoint` to your `/src` folder
  * Copy the folder `gemmlowp/internal` to your `/src` folder
* Get Ruy
  * First, run this to clone FixedPoint to your machine `git clone https://github.com/google/ruy.git`
  * Copy the file `ruy/ruy/profile/instrumentation.h` into `/src/ruy/profiler` (you will have to make the folder)
* Find any further reference code to get started at https://www.tensorflow.org/lite/microcontrollers/get_started_low_level
  * Include all of the necessary header files:
    `#include "tensorflow/lite/micro/all_ops_resolver.h"
    #include "tensorflow/lite/micro/micro_error_reporter.h"
    #include "tensorflow/lite/micro/micro_interpreter.h"
    #include "tensorflow/lite/schema/schema_generated.h"
    #include "tensorflow/lite/micro/micro_utils.h"` 
* Modify your `common.mk` file in your project to compile Tensorflow:
  * Change line with `MFLAGS` definition to `MFLAGS=-mcpu=cortex-a9 -mfpu=neon-fp16 -mfloat-abi=softfp -O3 -funsafe-math-optimizations -g` to try and optimize the code using pragmas
  * Change line with `INCLUDE` definition to `INCLUDE=$(foreach dir,$(INCDIR) $(EXTRA_INCDIR),-iquote"$(dir)") -I"$(ROOT)/src/"` to include all of the tensorflow includes in the compilation process (otherwise they will not be processed).
