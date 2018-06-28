#include <PixhawkArduinoMAVLink.h>
#include <HardwareSerial.h>

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

  imu.ReadAcceleration(&xacc, &yacc, &zacc);
  Serial.print("X: "); Serial.print(xacc);
  Serial.print("  Y: "); Serial.print(yacc);
  Serial.print("  Z: "); Serial.println(zacc);

  delay(100);
}
