#include <Servo.h>

Servo foot;
Servo seg;
Servo sho;

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

int height = 0;
int footPos = 0;
int segPos = 0;
int shoPos = 0;

//Max Hex Height
//foot = 80
//segment = 0

//Min Hex Height
//foot = 0
//segment = 80

void setup() {
  foot.attach(footPin); //lower pos = 0; middle pos = 115; upper pos = 180
  seg.attach(segPin); //lower pos = 0; middle pos = 45; upper pos = 180
  sho.attach(shoPin); //left pos = 180; middle pos = 90; right pos = 0
}

void loop() {
  //Stand (initial)
  foot.write(0); 
  footPos = 0;
  seg.write(80); 
  segPos = 80;
  sho.write(shoRest); 
  shoPos = shoRest;

  while(1){
    for(height = 0; height <= 20; height += 1){
      foot.write(footPos-20);
      seg.write(segPos+25);
      delay(250);
      sho.write(shoForward);
      delay(250);
      foot.write(footPos+=4);
      seg.write(segPos-=4);
      delay(250);
      sho.write(shoBack);
      delay(300);
    }
    for(height = 20; height >= 0; height -= 1){
      foot.write(footPos-20);
      seg.write(segPos+25);
      delay(250);
      sho.write(shoForward);
      delay(250);
      foot.write(footPos-=4);
      seg.write(segPos+=4);
      delay(250);
      sho.write(shoBack);
      delay(300);
    }
  }
}
