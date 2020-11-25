#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x3F, 16, 2);

bool crossing = true;

void setup() {
  lcd.begin();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Hello World!");
  pinMode(10, INPUT_PULLUP); //button input
  delay(2000);
}

void loop() {
  crossing = digitalRead(10);
  if (crossing == false) {
    text();
  }
  else {
    lcd.clear();
  }

}

void text() {
  delay(500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hello There");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("How Are You");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Have You Done");
  lcd.setCursor(0,1);
  lcd.print("Much");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("F**k You");
}
