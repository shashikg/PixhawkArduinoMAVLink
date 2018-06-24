#include <Arduino.h>
#include <PixhawkArduinoMAVLink.h>

// Please check for which digital pins can be used as RX/ TX for your respective board
// not all pins can be used with SoftwareSerial for virtual RX TX
#define _RX = 10; //(Connect it to TX of Pixhawk)
#define _TX = 11; //(Connect it to RX of Pixhawk)
PixhawkArduinoMAVLink imu(_RX, _TX);

void setup(){
  while(!imu.begin())
  Serial.begin(57600);
}

void loop(){
  float xacc, yacc, zacc;

  // ReadAcceleration function returns error code
  // 0 >> means succes
  // 1 >> error in parsing recieved data from Pixhawk
  // 2 >> error in reading the Pixhawk serial port
  imu.ReadAcceleration(&xacc, &yacc, &zacc);
  
  Serial.println("X: "); Serial.print(xacc);
  Serial.print("  Y: "); Serial.print(yacc);
  Serial.print("  Z: "); Serial.print(zacc);
}
