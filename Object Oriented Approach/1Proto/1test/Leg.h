#ifndef Leg_h
#define Leg_h

#include "Arduino.h"
#include "Joint.h"
#include "Leg.h"
#include "Adafruit_PWMServoDriver.h"
#include "jointPos.h"

class Leg
{
  public:
    Leg(int foot_pin, int segment_pin, int shoulder_pin, Adafruit_PWMServoDriver driver);
    void setTargets(POS input);
    void updateLeg();
    bool reachedTarget();
  private:
    Joint *_shoulder;
    Joint *_segment;
    Joint *_foot;
};

#endif
