/*
  PixhawkArduinoMAVLink.h - Library for using Arduino to recieve Pixhawk sensors data.
  Created by Shashi Kant, June 23, 2018.
  Using MAVLink C headers files generated from the ardupilotmega.xml with the help of mavgenerator.
*/

#ifndef PixhawkArduinoMAVLink_h
#define PixhawkArduinoMAVLink_h

#include "ardupilotmega/mavlink.h"
#include <SoftwareSerial.h>

class PixhawkArduinoMAVLink
{
  public:
    PixhawkArduinoMAVLink(int RX_PIN, int TX_PIN);
    bool begin();
    int ReadAcceleration(float *xacc, float *yacc, float *zacc);
  private:
    int _RX;
    int _TX;
    SoftwareSerial _MAVSerial;
};

#endif
