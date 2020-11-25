int interval;
boolean buttonStateA4 = true;
void setup() {
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(A4, INPUT_PULLUP);
}

void loop() {
interval = 2000;
buttonStateA4 = digitalRead(A4);
if(buttonStateA4 == false) {
forward();
backward();
}
else {
  stopMove();
}
}

void forward() {
  analogWrite(9, 200);
  analogWrite(10, 0);
  delay(interval);
}

void backward() {
  analogWrite(9, 0);
  analogWrite(10, 255);
  delay(interval);
}

void stopMove() {
  analogWrite(9, 0);
  analogWrite(10, 0);
}

