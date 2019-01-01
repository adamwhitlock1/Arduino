#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int Contrast = 100; 
int potPin = 2;
int potVal = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  analogWrite(6,Contrast);
}

void loop() {
    potVal = analogRead(potPin);
    delay(100);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(potVal);
    delay(250);
  // max number for potentiator is 1023 and min is 0
}
