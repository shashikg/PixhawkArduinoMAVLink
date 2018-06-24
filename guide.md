# Contents

| Serial No. | Tutorial Name | Link |
| ---------- | ------------- | ----- |
| 1 | How to use this library? | [Link](#How-to-use-this-Library?) |
| 2 | Reading Acceleration Data | [Link](#Reading-Acceleration-Data) |

# How to use this library?
Add the following header file: ```#include <PixhawkArduinoMAVLink.h>```
Define a RX, TX pins which is to be connected to Pixhawk see the exact connection for the Rpi on Pixhawk's website and replace Rpi with Arduino.
Create the PixhawkArduinoMAVLink object by using the following code ```PixhawkArduinoMAVLink mav(_RX, _TX);```
to start using it call the function: ```mav.begin();``` After that use the respective function which you need. See below for the use of different function.

# Reading Acceleration Data
**Function:** ```int ReadAcceleration(float *xacc, float *yacc, float *zacc)```
**Values to Pass:** 3 float address respectivly for xacc, yacc, zacc.
**Return Values:** 0 for success, 1 for error in parsing data, and 2 for error in reading serial.
