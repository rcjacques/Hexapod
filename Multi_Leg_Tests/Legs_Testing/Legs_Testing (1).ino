#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  110 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  540 // this is the 'maximum' pulse length count (out of 4096)

//Used to control leg position for foot, segment, and shoulder
struct POS{
  int foo;
  int seg;
  int sho;
};

const int RF_foot = 0;
const int RF_seg = 1;
const int RF_sho = 2;

const int RM_foot = 3;
const int RM_seg = 4;
const int RM_sho = 5;

const int RB_foot = 6;
const int RB_seg = 7;
const int RB_sho = 8;

const int LF_foot = 9;
const int LF_seg = 10;
const int LF_sho = 11;

const int LM_foot = 12; 
const int LM_seg = 13;
const int LM_sho = 14;

const int LB_foot = 15;
Servo LB_seg;
Servo LB_sho;

//Convert degrees to pulse length count
int d2p(int degrees){
  return map(degrees, 0, 180, SERVOMIN, SERVOMAX);
}

/*
 * Leg Positions
 */
//Right Front
POS RF_lift = {d2p(5),d2p(45),d2p(70)};
POS RF_rest = {d2p(50),d2p(0),d2p(70)};
POS RF_for_lift = {d2p(5),d2p(45),d2p(90)};
POS RF_back_lift = {d2p(5),d2p(45),d2p(30)};
POS RF_for_rest = {d2p(50),d2p(0),d2p(90)};
POS RF_back_rest = {d2p(50),d2p(0),d2p(30)};

//Right Middle
POS RM_lift = {d2p(10),d2p(100),d2p(70)};
POS RM_rest = {d2p(45),d2p(50),d2p(70)};
POS RM_for_lift = {d2p(10),d2p(100),d2p(110)};
POS RM_back_lift = {d2p(10),d2p(100),d2p(30)};
POS RM_for_rest = {d2p(45),d2p(50),d2p(110)};
POS RM_back_rest = {d2p(45),d2p(50),d2p(30)};

//Right Back
POS RB_lift = {d2p(20),d2p(100),d2p(60)};
POS RB_rest = {d2p(65),d2p(45),d2p(60)};
POS RB_for_lift = {d2p(20),d2p(100),d2p(100)};
POS RB_back_lift = {d2p(20),d2p(100),d2p(40)};
POS RB_for_rest = {d2p(65),d2p(45),d2p(100)};
POS RB_back_rest = {d2p(65),d2p(45),d2p(40)};

//Left Front
POS LF_lift = {d2p(10),d2p(70),d2p(70)};
POS LF_rest = {d2p(50),d2p(30),d2p(70)};
POS LF_for_lift = {d2p(10),d2p(70),d2p(50)};
POS LF_back_lift = {d2p(10),d2p(70),d2p(110)};
POS LF_for_rest = {d2p(50),d2p(30),d2p(50)};
POS LF_back_rest = {d2p(50),d2p(30),d2p(110)};

//Left Middle
POS LM_lift = {d2p(5),d2p(65),d2p(75)};
POS LM_rest = {d2p(35),d2p(25),d2p(75)};
POS LM_for_lift = {d2p(5),d2p(65),d2p(45)};
POS LM_back_lift = {d2p(5),d2p(65),d2p(100)};
POS LM_for_rest = {d2p(35),d2p(25),d2p(45)};
POS LM_back_rest = {d2p(35),d2p(25),d2p(100)};
  
//Left Back
POS LB_lift = {d2p(15),90,60};
POS LB_rest = {d2p(60),45,60};
POS LB_for_lift = {d2p(15),90,20};
POS LB_back_lift = {d2p(15),90,80};
POS LB_for_rest = {d2p(60),45,20};
POS LB_back_rest = {d2p(60),45,80};
/*
 * End Leg Positions
 */

void setup() {
  Serial.begin(9600);

  pwm.begin();
  LB_seg.attach(6);
  LB_sho.attach(3);
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  yield();
}

void all_rest(){
  pwm.setPWM(RF_foot, 0, RF_rest.foo); //
  pwm.setPWM(RF_seg, 0, RF_rest.seg); 
  pwm.setPWM(RF_sho, 0, RF_rest.sho); //
  
  pwm.setPWM(RM_foot, 0, RM_rest.foo); //
  pwm.setPWM(RM_seg, 0, RM_rest.seg); //
  pwm.setPWM(RM_sho, 0, RM_rest.sho); //

  pwm.setPWM(RB_foot, 0, RB_rest.foo); //
  pwm.setPWM(RB_seg, 0, RB_rest.seg); //
  pwm.setPWM(RB_sho, 0, RB_rest.sho); //

  pwm.setPWM(LF_foot, 0, LF_rest.foo); //
  pwm.setPWM(LF_seg, 0, LF_rest.seg); //
  pwm.setPWM(LF_sho, 0, LF_rest.sho); //

  pwm.setPWM(LM_foot, 0, LM_rest.foo); 
  pwm.setPWM(LM_seg, 0, LM_rest.seg); 
  pwm.setPWM(LM_sho, 0, LM_rest.sho); //

  pwm.setPWM(LB_foot, 0, LB_rest.foo); 
  LB_seg.write(LB_rest.seg);
  LB_sho.write(LB_rest.sho);
}

void all_lift(){
  pwm.setPWM(RF_foot, 0, RF_lift.foo); 
  pwm.setPWM(RF_seg, 0, RF_lift.seg); 
  pwm.setPWM(RF_sho, 0, RF_lift.sho); 
  
  pwm.setPWM(RM_foot, 0, RM_lift.foo); 
  pwm.setPWM(RM_seg, 0, RM_lift.seg); 
  pwm.setPWM(RM_sho, 0, RM_lift.sho); 

  pwm.setPWM(RB_foot, 0, RB_lift.foo); 
  pwm.setPWM(RB_seg, 0, RB_lift.seg); 
  pwm.setPWM(RB_sho, 0, RB_lift.sho); 

  pwm.setPWM(LF_foot, 0, LF_lift.foo); 
  pwm.setPWM(LF_seg, 0, LF_lift.seg); 
  pwm.setPWM(LF_sho, 0, LF_lift.sho); 

  pwm.setPWM(LM_foot, 0, LM_lift.foo); 
  pwm.setPWM(LM_seg, 0, LM_lift.seg); 
  pwm.setPWM(LM_sho, 0, LM_lift.sho); 

  pwm.setPWM(LB_foot, 0, LB_lift.foo); 
  LB_seg.write(LB_lift.seg);
  LB_sho.write(LB_lift.sho);
}

void tripod_lift_right(){
  //RF + LM + RB lift
  pwm.setPWM(RF_foot, 0, RF_lift.foo); 
  pwm.setPWM(RF_seg, 0, RF_lift.seg); 
  pwm.setPWM(RF_sho, 0, RF_lift.sho); 

  pwm.setPWM(LM_foot, 0, LM_lift.foo); 
  pwm.setPWM(LM_seg, 0, LM_lift.seg); 
  pwm.setPWM(LM_sho, 0, LM_lift.sho); 

  pwm.setPWM(RB_foot, 0, RB_lift.foo); 
  pwm.setPWM(RB_seg, 0, RB_lift.seg); 
  pwm.setPWM(RB_sho, 0, RB_lift.sho);
}

void tripod_for_rest_right(){
  //RF + LM + RB forward rest
  pwm.setPWM(RF_foot, 0, RF_for_rest.foo); 
  pwm.setPWM(RF_seg, 0, RF_for_rest.seg); 
  pwm.setPWM(RF_sho, 0, RF_for_rest.sho); 

  pwm.setPWM(LM_foot, 0, LM_for_rest.foo); 
  pwm.setPWM(LM_seg, 0, LM_for_rest.seg); 
  pwm.setPWM(LM_sho, 0, LM_for_rest.sho); 

  pwm.setPWM(RB_foot, 0, RB_for_rest.foo); 
  pwm.setPWM(RB_seg, 0, RB_for_rest.seg); 
  pwm.setPWM(RB_sho, 0, RB_for_rest.sho); 
}

void tripod_for_lift_right(){
  //RF + LM + RB forward
  pwm.setPWM(RF_foot, 0, RF_for_lift.foo); 
  pwm.setPWM(RF_seg, 0, RF_for_lift.seg); 
  pwm.setPWM(RF_sho, 0, RF_for_lift.sho); 

  pwm.setPWM(LM_foot, 0, LM_for_lift.foo); 
  pwm.setPWM(LM_seg, 0, LM_for_lift.seg); 
  pwm.setPWM(LM_sho, 0, LM_for_lift.sho); 

  pwm.setPWM(RB_foot, 0, RB_for_lift.foo); 
  pwm.setPWM(RB_seg, 0, RB_for_lift.seg); 
  pwm.setPWM(RB_sho, 0, RB_for_lift.sho); 
}

void tripod_back_rest_left(){
  //LF + RM + LB back
  pwm.setPWM(LF_foot, 0, LF_back_rest.foo); 
  pwm.setPWM(LF_seg, 0, LF_back_rest.seg); 
  pwm.setPWM(LF_sho, 0, LF_back_rest.sho); 

  pwm.setPWM(RM_foot, 0, RM_back_rest.foo); 
  pwm.setPWM(RM_seg, 0, RM_back_rest.seg); 
  pwm.setPWM(RM_sho, 0, RM_back_rest.sho); 

  pwm.setPWM(LB_foot, 0, LB_back_rest.foo); 
  LB_seg.write(LB_back_rest.seg); 
  LB_sho.write(LB_back_rest.sho); 
}

void tripod_lift_left(){
  //LF + RM + LB lift
  pwm.setPWM(LF_foot, 0, LF_lift.foo); 
  pwm.setPWM(LF_seg, 0, LF_lift.seg); 
  pwm.setPWM(LF_sho, 0, LF_lift.sho); 

  pwm.setPWM(RM_foot, 0, RM_lift.foo); 
  pwm.setPWM(RM_seg, 0, RM_lift.seg); 
  pwm.setPWM(RM_sho, 0, RM_lift.sho); 

  pwm.setPWM(LB_foot, 0, LB_lift.foo); 
  LB_seg.write(LB_lift.seg); 
  LB_sho.write(LB_lift.sho); 
}

void tripod_for_lift_left(){
  //LF + RM + LB forward lift
  pwm.setPWM(LF_foot, 0, LF_for_lift.foo); 
  pwm.setPWM(LF_seg, 0, LF_for_lift.seg); 
  pwm.setPWM(LF_sho, 0, LF_for_lift.sho); 

  pwm.setPWM(RM_foot, 0, RM_for_lift.foo); 
  pwm.setPWM(RM_seg, 0, RM_for_lift.seg); 
  pwm.setPWM(RM_sho, 0, RM_for_lift.sho); 

  pwm.setPWM(LB_foot, 0, LB_for_lift.foo); 
  LB_seg.write(LB_for_lift.seg); 
  LB_sho.write(LB_for_lift.sho); 
}

void tripod_back_rest_right(){
  //RF + LM + RB back rest
  pwm.setPWM(RF_foot, 0, RF_back_rest.foo); 
  pwm.setPWM(RF_seg, 0, RF_back_rest.seg); 
  pwm.setPWM(RF_sho, 0, RF_back_rest.sho); 

  pwm.setPWM(LM_foot, 0, LM_back_rest.foo); 
  pwm.setPWM(LM_seg, 0, LM_back_rest.seg); 
  pwm.setPWM(LM_sho, 0, LM_back_rest.sho); 

  pwm.setPWM(RB_foot, 0, RB_back_rest.foo); 
  pwm.setPWM(RB_seg, 0, RB_back_rest.seg); 
  pwm.setPWM(RB_sho, 0, RB_back_rest.sho); 
}

void tripod_for_rest_left(){
  //LF + RM + LB forward rest
  pwm.setPWM(LF_foot, 0, LF_for_rest.foo); 
  pwm.setPWM(LF_seg, 0, LF_for_rest.seg); 
  pwm.setPWM(LF_sho, 0, LF_back_rest.sho); 

  pwm.setPWM(RM_foot, 0, RM_for_rest.foo); 
  pwm.setPWM(RM_seg, 0, RM_for_rest.seg); 
  pwm.setPWM(RM_sho, 0, RM_for_rest.sho); 

  pwm.setPWM(LB_foot, 0, LB_back_rest.foo); 
  LB_seg.write(LB_for_rest.seg); 
  LB_sho.write(LB_for_rest.sho); 
}

//servo command: pwm.setPWM(SERVO_NUM, 0, PULSE_LENGTH);

void walk_forward_tripod(int num_steps){
  int pause = 500;
  bool right = true;

  for(int count = 0; count < num_steps; count++){
    if(right){
      //Right step
      delay(pause);
      tripod_lift_right();
      delay(pause);
      tripod_for_lift_right();
      //delay(pause);
      tripod_back_rest_left();
      delay(pause);
      tripod_for_rest_right();
      delay(pause);
      right = false;
    }
    else{
      //Left step
      delay(pause);
      tripod_lift_left();
      delay(pause);
      tripod_for_lift_left();
      //delay(pause);
      tripod_back_rest_right();
      delay(pause);
      tripod_for_rest_left();
      delay(pause);
      right = true;
    }
  }
}


void loop() {
  all_rest();
  walk_forward_tripod(3);
  all_rest();

  while(1){} //To prevent unwanted looping
}
