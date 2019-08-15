#ifndef Joint_h
#define Joint_h

#include "Arduino.h"
#include "Adafruit_PWMServoDriver.h"

class Joint
{
  public:
    Joint(int pin, Adafruit_PWMServoDriver driver);
    void setTarget(int target);
    void updateJoint();
    bool reachedTarget();
  private:
    Adafruit_PWMServoDriver _pwm;
    int _pin;
    int _target;
    int _currentPos;
    int _step = 5;
    int _nextPos;
    int d2p(int deg);
    bool _targetReached;
};

#endif
