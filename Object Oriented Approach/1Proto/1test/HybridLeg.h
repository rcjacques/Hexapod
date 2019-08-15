#ifndef Hybrid_Leg_h
#define Hybrid_Leg_h

#include "Arduino.h"
#include "HybridLeg.h"
#include "Joint.h"
#include "StandardJoint.h"
#include "Adafruit_PWMServoDriver.h"
#include "jointPos.h"

class Hybrid
{
  public:
    Hybrid(int foot_pin, int segment_pin, int shoulder_pin, Adafruit_PWMServoDriver driver);
    void setTargets(POS input);
    void updateLeg();
    bool reachedTarget();
  private:
    Joint *_shoulder;
    StandardJoint *_segment;
    StandardJoint *_foot;
};

#endif
