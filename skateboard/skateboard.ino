#include <Servo.h>
#define MaxServoTime 2400 //Real is 2400
#define MinServoTime 800 //Real is 800
#define MidServoTime 1500
volatile unsigned int servoTime = MidServoTime;
Servo motor;

void setup()
{
  Serial.begin(38400);
  motor.attach(10);
  Serial.setTimeout(30);
}

void loop()
{
  static int lastServoTime;
  while (Serial.available() > 0) {
    //Serial.write(Serial.read());
    servoTime = Serial.parseInt();
    if (servoTime == 0) {
      servoTime = lastServoTime;
    }
    else {
      lastServoTime = servoTime;
    }
    motor.writeMicroseconds(constrain(lastServoTime, MinServoTime, MaxServoTime));
 }
 //Serial.println(lastServoTime);
}

