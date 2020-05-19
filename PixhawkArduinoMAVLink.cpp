/*
  PixhawkArduinoMAVLink.cpp - Library for using Arduino to recieve Pixhawk's sensor data as well as some other usefull data which you might need.
  Created by Shashi Kant, June 23, 2018.
  Using MAVLink C headers files generated from the ardupilotmega.xml with the help of mavgenerator.
*/

#include "PixhawkArduinoMAVLink.h"

PixhawkArduinoMAVLink::PixhawkArduinoMAVLink(HardwareSerial &hs){
  _MAVSerial = &hs;
  MILLIG_TO_MS2 = 9.80665 / 1000.0;
  system_id = 1; // Your i.e. Arduino sysid
  component_id = 158; // Your i.e. Arduino compid
  type = MAV_TYPE_QUADROTOR;
  autopilot =  MAV_AUTOPILOT_INVALID;
}

bool PixhawkArduinoMAVLink::begin(){
  _MAVSerial->begin(57600);
  if(_MAVSerial->available()<=0){
    return 0;
  }else{
    return 1;
  }
}

// At first we will send some HeartBeats to Pixhawk to check whether it's available or not??
// After that we will check for whether we are recieving HeartBeats back from Pixhawk if Yes,
// We will note down its sysid and compid to send it a req to Stream Data.
void PixhawkArduinoMAVLink::Stream(){
  delay(2000);
  int flag=1;
  Serial.println("Sending Heartbeats...");
  mavlink_message_t msghb;
  mavlink_heartbeat_t heartbeat;
  uint8_t bufhb[MAVLINK_MAX_PACKET_LEN];
  mavlink_msg_heartbeat_pack(system_id, component_id, &msghb, type, autopilot, MAV_MODE_PREFLIGHT, 0, MAV_STATE_STANDBY);
  uint16_t lenhb = mavlink_msg_to_send_buffer(bufhb, &msghb);
  delay(1000);
  _MAVSerial->write(bufhb,lenhb);
  Serial.println("Heartbeats sent! Now will check for recieved heartbeats to record sysid and compid...");

  // Looping untill we get the required data.
  while(flag==1){
    delay(1);
    while(_MAVSerial->available()>0){
      mavlink_message_t msgpx;
      mavlink_status_t statuspx;
      uint8_t ch = _MAVSerial->read();
      if(mavlink_parse_char(MAVLINK_COMM_0, ch, &msgpx, &statuspx)){
        Serial.println("Message Parsing Done!");
        switch(msgpx.msgid){
          case MAVLINK_MSG_ID_HEARTBEAT:
          {
            mavlink_heartbeat_t packet;
            mavlink_msg_heartbeat_decode(&msgpx, &packet);
            received_sysid = msgpx.sysid; // Pixhawk sysid
            received_compid = msgpx.compid; // Pixhawk compid
            Serial.println("sysid and compid successfully recorded");
            flag = 0;
            break;
          }
        }
      }
    }
  }

  // Sending request for data stream...
  Serial.println("Now sending request for data stream...");
  delay(2000);
  mavlink_message_t msgds;
  uint8_t bufds[MAVLINK_MAX_PACKET_LEN];
  mavlink_msg_request_data_stream_pack(system_id, component_id, &msgds, received_sysid, received_compid, MAV_DATA_STREAM_ALL , 0x05, 1);
  uint16_t lends = mavlink_msg_to_send_buffer(bufds, &msgds);
  delay(1000);
  _MAVSerial->write(bufds,lends);
  Serial.println("Request sent! Now you are ready to recieve datas...");

}

void PixhawkArduinoMAVLink::ReadAcceleration(float *xacc, float *yacc, float *zacc){
  int flagI = 1;
  int flagA = 1;
  float xa, ya, za, q0, q1, q2, q3;

  while((flagI==1)||(flagA==1)){
    delay(10);
    while(_MAVSerial->available() > 0){
      mavlink_message_t msg;
      mavlink_status_t status1;
      uint8_t ch = _MAVSerial->read();
      // Serial.println(ch);
      if(mavlink_parse_char(MAVLINK_COMM_0, ch, &msg, &status1)){
        //Serial.println("Message Parsing Done!");
        switch(msg.msgid){
          case MAVLINK_MSG_ID_HIGHRES_IMU:
            {
              Serial.println("Sending Highres IMU Data");
              mavlink_highres_imu_t data;
              mavlink_msg_highres_imu_decode(&msg, &data);
              xa = (data.xacc);
              ya = (data.yacc);
              za = (data.zacc);
              flagI = 0;
              break;
            }
          case MAVLINK_MSG_ID_ATTITUDE_QUATERNION:
            {
              Serial.println("Sending Quaternion Attitude");
              mavlink_attitude_quaternion_t data;
              mavlink_msg_attitude_quaternion_decode(&msg, &data);
              q0 = data.q1;
              q1 = data.q2;
              q2 = data.q3;
              q3 = data.q4;
              flagA = 0;
              break;
            }
        }
      }
    }
  }

  *xacc = xa + (9.80665)*2*(q1*q3-q0*q2);
  *yacc = ya + (9.80665)*2*(q0*q1+q3*q2);
  *zacc = za + (9.80665)*(1-2*(q1*q1+q2*q2));

  return;
}
