#include <Servo.h>

Servo foot;
Servo segment;
Servo shoulder;

const int footPin = 1;
const int segPin = 5;
const int shoPin = 3;

const int footStand = 60;
const int footLift = 40;
const int segStand = 20;
const int segLift = 45;
const int shoRest = 90;
const int shoForward = 45;
const int shoBack = 135;

void setup() {
  foot.attach(footPin); //lower pos = 0; middle pos = 115; upper pos = 180
  segment.attach(segPin); //lower pos = 0; middle pos = 45; upper pos = 180
  shoulder.attach(shoPin); //left pos = 180; middle pos = 90; right pos = 0
}

void loop() {
  //Stand (initial)
  foot.write(footStand); 
  segment.write(segStand); 
  shoulder.write(shoRest); 
  delay(500);

  while(1){
    //Lift
    foot.write(footLift); 
    segment.write(segLift); 
    delay(250);
  
    //Rotate  
    shoulder.write(shoForward); 
    delay(250);
    
    //Lower
    foot.write(footStand); 
    segment.write(segStand);  
    delay(250);
    
    //Walk 
    shoulder.write(shoBack); 
    delay(300);
  }
}
