/*
  PixhawkArduinoMAVLink.h - Library for using Arduino to recieve Pixhawk sensors data.
  Created by Shashi Kant, June 23, 2018.
  Using MAVLink C headers files for the ardupilotmega one.
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
    void ReadAcceleration(float *xacc, float *yacc, float *zacc, bool *success);
  private:
    int _RX;
    int _TX;
    SoftwareSerial _MAVSerial;
};

#endif
