#include "Arduino.h"
#include "Joint.h"
#include "Adafruit_PWMServoDriver.h"

Joint::Joint(int pin, Adafruit_PWMServoDriver driver)
{
  _pin = pin;
  _pwm = driver;
}

void Joint::setTarget(int target)
{
  _target = target;
}

void Joint::updateJoint()
{
  int _tolerance = 2;
  if(_currentPos > _target+_tolerance)
  {
    _nextPos -= _step;
    _targetReached = false;
  }
  else if(_currentPos < _target-_tolerance)
  {
    _nextPos += _step;
    _targetReached = false;
  }
  else
  {
    _targetReached = true;
  }
  
  _pwm.setPWM(_pin, 0, _nextPos);
  _currentPos = _nextPos;
}

int Joint::d2p(int deg)
{
  return map(deg, 0, 180, 110, 540);
}

bool Joint::reachedTarget()
{
  return _targetReached;
}

