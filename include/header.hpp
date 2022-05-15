#ifndef _HEADER_
#define _HEADER_

#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <cerrno>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <unistd.h>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include "main.h"
#include "tensorflow/lite/micro/all_ops_resolver.h"
#include "AI-model.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/micro_utils.h"
#include "tensorflow/lite/schema/schema_generated.h"
using namespace std;
using namespace pros;
#define ljx E_CONTROLLER_ANALOG_LEFT_X
#define ljy E_CONTROLLER_ANALOG_LEFT_Y
#define rjx E_CONTROLLER_ANALOG_RIGHT_X
#define rjy E_CONTROLLER_ANALOG_RIGHT_Y
#define buttonA E_CONTROLLER_DIGITAL_A
#define buttonY E_CONTROLLER_DIGITAL_Y
#define buttonX E_CONTROLLER_DIGITAL_X
#define buttonB E_CONTROLLER_DIGITAL_B
#define buttonLeft E_CONTROLLER_DIGITAL_LEFT
#define buttonRight E_CONTROLLER_DIGITAL_RIGHT
#define buttonUp E_CONTROLLER_DIGITAL_UP
#define buttonDown E_CONTROLLER_DIGITAL_DOWN
#define buttonR1 E_CONTROLLER_DIGITAL_R1
#define buttonR2 E_CONTROLLER_DIGITAL_R2
#define buttonL1 E_CONTROLLER_DIGITAL_L1
#define buttonL2 E_CONTROLLER_DIGITAL_L2
#define Accel c::imu_accel_s_t
#define Digout ADIDigitalOut
#define visionSig vision_signature_s_t
#define visionOb vision_object_s_t
#define Ultrasonic ADIUltrasonic
#define PI 3.14159265
#define TENSOR_ARENA_SIZE (4096 * 1024) // allocate 4k for tensor arena
#define NUM_BYTES_TO_PRINT 100
#define f first
#define s second
typedef enum { PURPLE = 1, YELLOW = 2, BLUE = 3, RED = 4, NONE = 5 } Color;
typedef enum { FRONT = 1, BACK = 2, RIGHT = 3, LEFT = 4 } Side;
typedef enum { LEFTN = 1, MIDDLEN = 2, RIGHTN = 3 } Neutral;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

#endif
