#include <Servo.h>

Servo foot;
Servo segment;
Servo shoulder;

const int footPin = 1;
const int segmentPin = 5;
const int shoulderPin = 3;

int pos = 0;

void setup() {
  foot.attach(footPin);
  segment.attach(segmentPin);
  shoulder.attach(shoulderPin);
}

void loop() {
  foot.write(115); //lower pos = 0; middle pos = 115; upper pos = 180
  segment.write(45); //lower pos = 0; middle pos = 45; upper pos = 180
  shoulder.write(90); //left pos = 180; middle pos = 90; right pos = 0
  delay(500);
  shoulder.write(180);
  delay(500);
  shoulder.write(0);
  delay(500);
  segment.write(100);
  delay(1000);
  foot.write(30);
  delay(250);
  foot.write(90);
  delay(250);
  foot.write(30);
  delay(250);
  foot.write(90);
  delay(250);
  foot.write(30);
  delay(250);
  foot.write(90);
  delay(2000);
  foot.write(115); //lower pos = 0; middle pos = 115; upper pos = 180
  segment.write(45); //lower pos = 0; middle pos = 45; upper pos = 180
  shoulder.write(90); //left pos = 180; middle pos = 90; right pos = 0
  while(1){}
}
