int count = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(count);
  count++;

  delay(2);
}
