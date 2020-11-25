int interval;
boolean buttonStateA4 = true;
boolean buttonStateA3 = true;
void setup() {
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(A4, INPUT_PULLUP);
pinMode(A3, INPUT_PULLUP);
}

void loop() {
  buttonStateA4 = digitalRead(A4);
  buttonStateA3 = digitalRead(A3);
if(buttonStateA4 == false) {
chaseGo();
}
if(buttonStateA3 == false) {
flashGo();
}

}

void chaseGo() {
interval =  20;
digitalWrite(7,HIGH);
delay(interval);
digitalWrite(6,HIGH);
delay(interval);
digitalWrite(5,HIGH);
delay(interval);
digitalWrite(4,HIGH);
delay(interval);
digitalWrite(3,HIGH);
delay(interval);
digitalWrite(2,HIGH);
delay(interval);
digitalWrite(7,LOW);
delay(interval);
digitalWrite(6,LOW);
delay(interval);
digitalWrite(5,LOW);
delay(interval);
digitalWrite(4,LOW);
delay(interval);
digitalWrite(3,LOW);
delay(interval);
digitalWrite(2,LOW);
delay(interval);
}

void flashGo(){
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  delay(interval);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delay(interval);
}

