int light = 0;
void setup() {
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
}

void loop() {
for(int v = 0; v < 255; v = v + 5) {
analogWrite(3, v);
analogWrite(5, v);
analogWrite(6, v);
//light = light + 5;
delay(10);
//if (light == 255) {light = 0;}
}
//if (light == 0) {digitalWrite(7, HIGH); digitalWrite(4, HIGH); digitalWrite(2, HIGH);}
//else {digitalWrite(7, LOW); digitalWrite(4, LOW); digitalWrite(2, LOW);}
for(int v = 255; v < 0; v = v - 5) {
analogWrite(3, v);
analogWrite(5, v);
analogWrite(6, v);
//light = light + 5;
delay(10);
//if (light == 255) {light = 0;}
}
}
