# VEX-V5-Tensorflow
This is a sample PROS (https://pros.cs.purdue.edu/) project with Tensorflow Lite support.

This project was designed to allow all competitors in the VEX robotics competitions to use machine learning inference on their robots.

It includes a subset of the TFLite Micro, flatbuffers, fixedpoint, ruy libraries, and a modified makefile/common.mk to compile them without the need for Bazel.

Looking forward to seeing amazing uses of this tool in future VEX competitions! We imagine Tensorflow to be usable for sensor fusion, SLAM, and more.

# Getting Started
You have one of two options:

## a. Clone this project and edit it
This option is easier if you either did not make a project yet or have a somewhat simple project which can be tampered with. The current project will run a sample MNIST model and print a predicted digit based on the data it is given.

