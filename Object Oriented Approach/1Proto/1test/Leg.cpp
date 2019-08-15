#include "Arduino.h"
#include "Joint.h"
#include "Leg.h"
#include "Adafruit_PWMServoDriver.h"
#include "jointPos.h"

Leg::Leg(int foot_pin, int segment_pin, int shoulder_pin, Adafruit_PWMServoDriver driver)
{
  _shoulder = new Joint(shoulder_pin, driver);
  _segment = new Joint(segment_pin, driver);
  _foot = new Joint(foot_pin, driver);
}

void Leg::setTargets(POS input)
{
  _shoulder->setTarget(input.sho);
  _segment->setTarget(input.seg);
  _foot->setTarget(input.foo);
}

void Leg::updateLeg()
{
  _shoulder->updateJoint();
  _segment->updateJoint();
  _foot->updateJoint();
}

bool Leg::reachedTarget()
{
  return _shoulder->reachedTarget() && _segment->reachedTarget() && _foot->reachedTarget();
}

