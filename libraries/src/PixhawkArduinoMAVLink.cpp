/*
  PixhawkArduinoMAVLink.cpp - Library for using Arduino to recieve Pixhawk sensors data.
  Created by Shashi Kant, June 23, 2018.
  Using MAVLink C headers files generated from the ardupilotmega.xml with the help mavgenerator.
*/

#include "ardupilotmega/mavlink.h"
#include "PixhawkArduinoMAVLink.h"
#include <SoftwareSerial.h>

PixhawkArduinoMAVLink::PixhawkArduinoMAVLink(int RX_PIN, int TX_PIN){
  _MAVSerial = SoftwareSerial(RX_PIN, TX_PIN);
  _RX = RX_PIN;
  _TX = TX_PIN;
}

bool PixhawkArduinoMAVLink::begin(){
  _MAVSerial.begin(57600);
  return _MAVSerial;
}

void PixhawkArduinoMAVLink::ReadAcceleration(float *xacc, float *yacc, float *zacc, bool *success){
  mavlink_message_t msg;
  mavlink_status_t status;

  if(_MAVSerial.available()){
    uint8_t ch = _MAVSerial.read();
    if(mavlink_parse_char(MAVLINK_COMM_0, ch, &msg, &status)){
      switch(msg.msgid){
        case MAVLINK_MSG_ID_HIL_SENSOR:
        {
          mavlink_hil_sensor_t imu;
          mavlink_msg_hil_sensor_decode(&msg, &imu);
          xacc = imu.xacc;
          yacc = imu.yacc;
          zacc = imu.zacc;
        }break;
      }
    }
  }
}
