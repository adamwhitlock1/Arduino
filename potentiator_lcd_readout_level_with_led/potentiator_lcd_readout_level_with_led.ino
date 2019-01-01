#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int Contrast = 100; 
int redPin = 1;
int greenPin = 10;
int bluePin = 9;
int potPin = 2;
int potVal = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  analogWrite(6,Contrast);
  lcd.begin(16, 2);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
    delay(250);
    potVal = analogRead(potPin);
    delay(100);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(potVal);
    if (potVal < 341 ) {
      digitalWrite(greenPin,HIGH);
      digitalWrite(bluePin,LOW);
      digitalWrite(redPin,LOW);
      lcd.setCursor(0, 1);
      lcd.print("LOW    ");
    }
    if (potVal > 341 ) {
      digitalWrite(greenPin,LOW);
      digitalWrite(bluePin,HIGH);
      digitalWrite(redPin,LOW);
      lcd.setCursor(0, 1);
      lcd.print("MED   ");
    }
    if (potVal > 682 ) {
      digitalWrite(greenPin,LOW);
      digitalWrite(bluePin,LOW);
      digitalWrite(redPin,HIGH);
      lcd.setCursor(0, 1);
      lcd.print("HIGH  ");
    }
    if (potVal == 1023 ) {
      digitalWrite(greenPin,HIGH);
      digitalWrite(bluePin,HIGH);
      digitalWrite(redPin,HIGH);
      lcd.setCursor(0, 1);
      lcd.print("MAX   ");
    }

    if (potVal == 0 ) {
            digitalWrite(greenPin,HIGH);
      digitalWrite(bluePin,LOW);
      digitalWrite(redPin,LOW);
      lcd.setCursor(0, 1);
      lcd.print("OFF   ");
    }
    
    delay(500);
}
