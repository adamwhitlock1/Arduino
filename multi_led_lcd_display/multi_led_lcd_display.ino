#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int Contrast = 100; 
int switchPin = 8;
boolean lastButton = LOW;
boolean currentButton = LOW;
int ledCount = 0;
int redPin = 1;
int greenPin = 10;
int bluePin = 9;
int potPin = 2;
int potVal = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  analogWrite(6,Contrast);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Happy 2019!");
  lcd.setCursor(0, 1);
  lcd.print("Press the button");
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

boolean debounce(boolean last) {
  boolean current = digitalRead(switchPin);
  if (last != current) {
    delay(5);
    current = digitalRead(switchPin);
  }
  return current;
}


void loop() {
  currentButton = debounce(lastButton);
  if (ledCount == 0) { 
    digitalWrite(greenPin,HIGH);
    } else {
      digitalWrite(greenPin,LOW);
    }

    potVal = analogRead(potPin);
    delay(100);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(potVal);
    delay(250);
    
  
  if ( lastButton == LOW  && currentButton == HIGH ) {
    ledCount = ledCount + 1;
    if ( ledCount % 2 ) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ODD           ");
      lcd.setCursor(0, 1);
      lcd.print(ledCount);
      digitalWrite(redPin,HIGH);
      digitalWrite(bluePin,LOW);
      digitalWrite(greenPin,LOW);
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("EVEN          ");
      lcd.setCursor(0, 1);
      lcd.print(ledCount);
      digitalWrite(bluePin,HIGH);
      digitalWrite(redPin,LOW);
      digitalWrite(greenPin,LOW);
    }
  }
  lastButton = currentButton;
 
  // print the number of seconds since reset:
  
  
}
