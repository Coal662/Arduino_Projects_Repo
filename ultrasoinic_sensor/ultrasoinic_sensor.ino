#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x3F, 16, 2);

const int buzzer = 6; //buzzer to arduino pin 6
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
float distance;



void setup() {
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT); // Set buzzer - pin 6 as an outpu
Serial.begin(9600); // Starts the serial communication
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
lcd.clear();
lcd.print(distance);
tone(buzzer, distance*2); // Send 1KHz sound signal...
delay(300);
}
