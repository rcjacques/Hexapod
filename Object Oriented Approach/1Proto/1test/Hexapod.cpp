#include "Arduino.h"
#include "Leg.h"
#include "HybridLeg.h"
#include "Hexapod.h"
#include "Adafruit_PWMServoDriver.h"
#include "jointPos.h"
//#include "list.h"


POS RF_REST = {50,0,70};
POS RM_REST = {45,50,70};
POS RB_REST = {65,45,60};
POS LF_REST = {50,30,70};
POS LM_REST = {35,25,75};
POS LB_REST = {60,45,60};

POS RF_LIFT = {5,45,70};
POS RM_LIFT = {10,100,70};
POS RB_LIFT = {20,100,60};
POS LF_LIFT = {10,70,70};
POS LM_LIFT = {5,65,75};
POS LB_LIFT = {15,90,60};

POS RF_LIFT_FORWARD = {5,45,90};
POS RM_LIFT_FORWARD = {10,100,110};
POS RB_LIFT_FORWARD = {20,100,100};
POS LF_LIFT_FORWARD = {10,70,50};
POS LM_LIFT_FORWARD = {5,65,45};
POS LB_LIFT_FORWARD = {15,90,20};

POS RF_LIFT_BACKWARD = {5,45,30};
POS RM_LIFT_BACKWARD = {10,100,30};
POS RB_LIFT_BACKWARD = {20,100,40};
POS LF_LIFT_BACKWARD = {10,70,110};
POS LM_LIFT_BACKWARD = {5,65,100};
POS LB_LIFT_BACKWARD = {15,90,80};

POS RF_REST_FORWARD = {50,0,90};
POS RM_REST_FORWARD = {45,50,110};
POS RB_REST_FORWARD = {65,45,100};
POS LF_REST_FORWARD = {50,30,50};
POS LM_REST_FORWARD = {35,25,45};
POS LB_REST_FORWARD = {60,45,20};

POS RF_REST_BACKWARD = {50,0,30};
POS RM_REST_BACKWARD = {45,50,30};
POS RB_REST_BACKWARD = {65,45,40};
POS LF_REST_BACKWARD = {50,30,110};
POS LM_REST_BACKWARD = {35,25,100};
POS LB_REST_BACKWARD = {60,45,80};

Hexapod::Hexapod(Adafruit_PWMServoDriver pwm)
{
  _pwm = pwm;

  _right_front = new Leg(0,1,2,_pwm);
  _right_middle = new Leg(3,4,5,_pwm);
  _right_back = new Leg(6,7,8,_pwm);
  _left_front = new Leg(9,10,11,_pwm);
  _left_middle = new Leg(12,13,14,_pwm);
//  _left_back = new Hybrid(15,6,3,_pwm);
}

void Hexapod::initialize()
{
//  Serial.println(1);
  _right_front->setTargets(RF_REST);
  _right_middle->setTargets(RM_REST);
  _right_back->setTargets(RB_REST);
  _left_front->setTargets(LF_REST);
  _left_middle->setTargets(LM_REST);
//  _left_back->setTargets(LB_REST);

  while(!_right_front->reachedTarget() && !_right_middle->reachedTarget() && !_right_back->reachedTarget() && 
        !_left_front->reachedTarget() && !_left_middle->reachedTarget() && !_left_back->reachedTarget())
  {
    _right_front->updateLeg();
    _right_middle->updateLeg();
    _right_back->updateLeg();
    _left_front->updateLeg();
    _left_middle->updateLeg();
//    _left_back->updateLeg();
  }
}

void Hexapod::forward(int steps)
{
  int leg = 0;
//  list <int>
  
  while(steps > 0){
    leg = steps % 2;

    switch(leg){
      case 0:
        if(_right_front->reachedTarget())
        {
          //set new target
        }
    }
  }
}

void Hexapod::backward(int steps)
{
  
}

void Hexapod::strafe_left(int steps)
{
  
}

void Hexapod::strafe_right(int steps)
{
  
}

void Hexapod::turn_left(int steps)
{
  
}

void Hexapod::turn_right(int steps)
{
  
}

void Hexapod::stand(int height)
{
  
}

void Hexapod::updateAll()
{
  _right_front->updateLeg();
  _right_middle->updateLeg();
  _right_back->updateLeg();
  _left_front->updateLeg();
  _left_middle->updateLeg();
  _left_back->updateLeg();
}

