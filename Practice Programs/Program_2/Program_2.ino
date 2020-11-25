int interval;

void setup() {
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
}

void loop() {
interval =  7;
evenOn();
evenOff();
oddOn();
oddOff();
}

void evenOn() {
digitalWrite(2, HIGH);
digitalWrite(4, HIGH);
digitalWrite(6, HIGH); 
delay(interval);
}

void oddOn() {
digitalWrite(3, HIGH);
digitalWrite(5, HIGH);
digitalWrite(7, HIGH);
delay(interval);
}

void evenOff() {
digitalWrite(2, LOW);
digitalWrite(4, LOW);
digitalWrite(6, LOW); 
delay(interval);
}

void oddOff() {
digitalWrite(3, LOW);
digitalWrite(5, LOW);
digitalWrite(7, LOW);
delay(interval);
}
