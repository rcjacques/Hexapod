#include <Arduino.h>
#include <Hexapod.h>
#include "Adafruit_PWMServoDriver.h"

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setup() {
  Serial.begin(9600);

  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  yield();
}

Hexapod hex(pwm);

void loop() {
  Serial.println("check");
  hex.initialize();
//  hex.forward(1);
  
//  while(1); //to prevent continuous looping
}
