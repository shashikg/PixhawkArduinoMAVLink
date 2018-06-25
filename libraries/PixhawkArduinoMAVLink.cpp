/*
  PixhawkArduinoMAVLink.cpp - Library for using Arduino to recieve Pixhawk sensors data.
  Created by Shashi Kant, June 23, 2018.
  Using MAVLink C headers files generated from the ardupilotmega.xml with the help of mavgenerator.
*/

#include "src/ardupilotmega/mavlink.h"
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "PixhawkArduinoMAVLink.h"

PixhawkArduinoMAVLink::PixhawkArduinoMAVLink(int RX_PIN, int TX_PIN){
  _MAVSerial = new SoftwareSerial(RX_PIN, TX_PIN);
  _RX = RX_PIN;
  _TX = TX_PIN;
}

bool PixhawkArduinoMAVLink::begin(){
  _MAVSerial->begin(57600);
  if(_MAVSerial->available()){
    return 1;
  }else{
    return 0;
  }
}

int PixhawkArduinoMAVLink::ReadAcceleration(float *xacc, float *yacc, float *zacc){
  mavlink_message_t msg;
  mavlink_status_t status;

  if(_MAVSerial->available()){
    uint8_t ch = _MAVSerial->read();
    if(mavlink_parse_char(MAVLINK_COMM_0, ch, &msg, &status)){
      switch(msg.msgid){
        case MAVLINK_MSG_ID_HIL_SENSOR:
        {
          mavlink_hil_sensor_t data;
          mavlink_msg_hil_sensor_decode(&msg, &data);
          *xacc = data.xacc;
          *yacc = data.yacc;
          *zacc = data.zacc;
          return 0;
        }break;
      }
    }else{
      return 1;
    }
  }else{
    return 2;
  }
}
