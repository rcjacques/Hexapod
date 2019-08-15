#include "Arduino.h"
#include "Joint.h"
#include "StandardJoint.h"
#include "HybridLeg.h"
#include "Adafruit_PWMServoDriver.h"
#include "jointPos.h"

Hybrid::Hybrid(int foot_pin, int segment_pin, int shoulder_pin, Adafruit_PWMServoDriver driver)
{
  _shoulder = new Joint(shoulder_pin, driver);
  _segment = new StandardJoint(segment_pin);
  _foot = new StandardJoint(foot_pin);
}

void Hybrid::setTargets(POS input)
{
  _shoulder->setTarget(input.sho);
  _segment->setTarget(input.seg);
  _foot->setTarget(input.foo);
}

void Hybrid::updateLeg()
{
  _shoulder->updateJoint();
  _segment->updateJoint();
  _foot->updateJoint();
}

bool Hybrid::reachedTarget()
{
  return _shoulder->reachedTarget() && _segment->reachedTarget() && _foot->reachedTarget();
}

