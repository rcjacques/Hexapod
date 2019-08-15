#include "Arduino.h"
#include "StandardJoint.h"
#include "Adafruit_PWMServoDriver.h"

StandardJoint::StandardJoint(int pin)
{
  _servo.attach(pin);
}

void StandardJoint::setTarget(int target)
{
  _target = target;
}

void StandardJoint::updateJoint()
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
  
  _servo.write(_nextPos);
  _currentPos = _nextPos;
}


bool StandardJoint::reachedTarget()
{
  return _targetReached;
}

