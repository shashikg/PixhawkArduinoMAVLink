# Guide
## Contents

| Serial No. | Tutorial Name | Link |
| ---------- | ------------- | ----- |
| 1 | How to use this library? | [Link](#how-to-use-this-library) |
| 2 | Reading Acceleration Data | [Link](#reading-acceleration-data) |

## How to use this library?
Add the following header files to your arduino script:
```
#include <PixhawkArduinoMAVLink.h>
#include <HardwareSerial.h>
```
Define a ```HardwareSerial``` which is to be connected to Pixhawk see the exact connection for the Rpi on Pixhawk's website and replace Rpi with Arduino.

![Connection for Pixhawk 2](RaspberryPi_Pixhawk_wiring1.jpg)

Create the PixhawkArduinoMAVLink object by using the following code:
```
HardwareSerial &hs = Serial1;
PixhawkArduinoMAVLink mav(hs);
```
to start using it call the function:
```
mav.begin(); // to start the serial
mav.Stream(); // to initialise Pixhawk and send a req to stream data
```
After that use the respective function which you need. See below for the use of different function.

## Reading Acceleration Data
Gives the actual acceleration values after compensating **g** from the imu acceleration data! Uses Quaternion Attitude and High Res IMU Data from Pixhawk. Simply call the function your acceleration datas will be saved in your passed variables.

**Function:** ```void ReadAcceleration(float *xacc, float *yacc, float *zacc)```

**Values to Pass:** 3 float address respectively for xacc, yacc, zacc.
