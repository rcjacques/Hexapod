#ifndef StandardJoint_h
#define StandardJoint_h

#include "Arduino.h"
#include "Servo.h"
#include "Adafruit_PWMServoDriver.h"

class StandardJoint
{
  public:
    StandardJoint(int pin);
    void setTarget(int target);
    void updateJoint();
    bool reachedTarget();
  private:
    Servo _servo;
    int _target;
    int _currentPos;
    int _step = 5;
    int _nextPos;
    bool _targetReached;
};

#endif
