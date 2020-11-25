#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 20, 4);

char _1[17] = {'F','u','c','k',' ','Y','o','u',' ','M','r',' ','D','r','e','w'};

void setup() {
  lcd.begin();
  lcd.backlight();
}

void loop() {
  lcd.setCursor(0,0);

  for(int k = 0; k < 16; k++) {
    lcd.print(_1[k]);
    delay(250);
  }

  delay(2000);
  lcd.clear();
  delay(1000);
}
