int led = 9;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

int sensorValue = analogRead(A0);
int brightness = 0;
float voltage = sensorValue*(5.0/1023.0);
int fadeAmount = voltage*voltage;

Serial.println(voltage);

analogWrite(led, brightness);

brightness = brightness + fadeAmount;

if(brightness == 0 || brightness == 255){
  fadeAmount = -fadeAmount ;
}
delay(300);
}
