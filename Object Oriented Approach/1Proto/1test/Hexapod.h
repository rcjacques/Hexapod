#ifndef Hexapod_h
#define Hexapod_h

#include "Arduino.h"
#include "Leg.h"
#include "HybridLeg.h"
#include "Adafruit_PWMServoDriver.h"

class Hexapod
{
  public:
    Hexapod(Adafruit_PWMServoDriver pwm);
    void initialize();
    void forward(int steps);
    void backward(int steps);
    void strafe_left(int steps);
    void strafe_right(int steps);
    void turn_left(int steps);
    void turn_right(int steps);
    void stand(int height);
    void updateAll();
  private:
    Adafruit_PWMServoDriver _pwm;
    Leg *_right_front;
    Leg *_right_middle;
    Leg *_right_back;
    Leg *_left_front;
    Leg *_left_middle;
    Hybrid *_left_back;
};

#endif
