#include <PixhawkArduinoMAVLink.h>
#include <SoftwareSerial.h>
#include <HardwareSerial.h>

// Please check for which digital pins can be used as RX/ TX for your respective board
// not all pins can be used with SoftwareSerial for virtual RX TX
HardwareSerial &hs = Serial1;
PixhawkArduinoMAVLink imu(hs);

void setup(){
  Serial.begin(57600);
  while(!imu.begin()){
    Serial.println("Not Connected!");
    delay(1000);
  }

  imu.Stream();
  delay(2000);
}

void loop(){
  float xacc, yacc, zacc;

  // ReadAcceleration function returns error code
  // 0 >> means succes
  // 1 >> parsing done but not recieved imu data
  // 2 >> error in parsing recieved data from Pixhawk
  // 3 >> error in reading the Pixhawk serial port
  int stat;
  stat = imu.ReadAcceleration(&xacc, &yacc, &zacc);

  if (stat==0){
    Serial.print("X: "); Serial.print(xacc);
    Serial.print("  Y: "); Serial.print(yacc);
    Serial.print("  Z: "); Serial.println(zacc);
  }
  delay(10);
}
