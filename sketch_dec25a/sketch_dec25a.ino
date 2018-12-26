
// blink led

int ledPin = 13;

void setup() {

//  initialize the pins as outputs
pinMode(ledPin, OUTPUT);

}

void loop() {

digitalWrite(ledPin, HIGH);
delay(1500);
digitalWrite(ledPin, LOW);
delay(1500);
  
}`
