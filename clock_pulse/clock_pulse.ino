int resetTime = 1;
bool run2 = true;
bool run3 = true;
bool run4 = true;
bool run5 = true;
bool run6 = true;
bool run7 = true;
bool run8 = true;
bool run9 = true;
bool run10 = true;
int delayTime = 0;

void setup() {
pinMode(5, OUTPUT);
pinMode(10, OUTPUT);
pinMode(A3, INPUT);
digitalWrite(10, HIGH);
}

void loop() {
  delayTime = analogRead(A3);
  if((resetTime == 2) && (run2 == true)) {
    resetTime = 1;
    run2 = false;
    digitalWrite(10, HIGH);
    digitalWrite(10, LOW);
  }
  else if((resetTime == 3) && (run3 == true)) {
    resetTime = 1;
    run3 = false;
    digitalWrite(10, HIGH);
    digitalWrite(10, LOW);
  }
  else if((resetTime == 4) && (run4 == true)) {
    resetTime = 1;
    run4 = false;
    digitalWrite(10, HIGH);
    digitalWrite(10, LOW);
  }
  else if((resetTime == 5) && (run5 == true)) {
    resetTime = 1;
    run5 = false;
    digitalWrite(10, HIGH);
    digitalWrite(10, LOW);
  }
  else if((resetTime == 6) && (run6 == true)) {
    resetTime = 1;
    run6 = false;
    digitalWrite(10, HIGH);
    digitalWrite(10, LOW);
  }
  else if((resetTime == 7) && (run7 == true)) {
    resetTime = 1;
    run7 = false;
    digitalWrite(10, HIGH);
    digitalWrite(10, LOW);
  }
  else if((resetTime == 8) && (run8 == true)) {
    resetTime = 1;
    run8 = false;
    digitalWrite(10, HIGH);
    digitalWrite(10, LOW);
  }
  else if((resetTime == 9) && (run9 == true)) {
    resetTime = 1;
    run9 = false;
    digitalWrite(10, HIGH);
    digitalWrite(10, LOW);
  }
  else if((resetTime == 10) && (run10 == true)) {
    resetTime = 1;
    run10 = false;
    digitalWrite(10, HIGH);
    digitalWrite(10, LOW);
  }
  digitalWrite(5, HIGH);
  delay(delayTime);
  digitalWrite(5, LOW);
  resetTime = resetTime + 1;
  delay(delayTime);
}
