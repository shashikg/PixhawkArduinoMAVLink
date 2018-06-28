/*
  PixhawkArduinoMAVLink.h - Library for using Arduino to recieve Pixhawk sensors data.
  Created by Shashi Kant, June 23, 2018.
  Using MAVLink C headers files generated from the ardupilotmega.xml with the help of mavgenerator.
*/

#ifndef PixhawkArduinoMAVLink_h
#define PixhawkArduinoMAVLink_h

#include "src/ardupilotmega/mavlink.h"
#include <src/checksum.h>
#include <src/mavlink_types.h>
#include <src/protocol.h>
#include <Arduino.h>
#include <HardwareSerial.h>

class PixhawkArduinoMAVLink
{
  public:
    PixhawkArduinoMAVLink(HardwareSerial &hs);
    bool begin();
    void ReadAcceleration(float *xacc, float *yacc, float *zacc);
    void Stream();
  private:
    HardwareSerial* _MAVSerial;
    double MILLIG_TO_MS2;
    uint8_t system_id;
    uint8_t component_id;
    uint8_t type;
    uint8_t autopilot;
    uint8_t received_sysid; // Pixhawk sysid
    uint8_t received_compid; // Pixhawk compid
};

#endif
