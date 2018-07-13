choose corresponding board type and port type for you project. Then load up the following sketch onto your Arduino.

const int sigPin = 2; // the number of the tilt switch pin
const int buzzerPin = 9; // the number of the LED pin
// variables will change:
boolean sigState = 0; // variable for reading the tilt switch status
void setup()
{
  // initialize the LED pin as an output:
  pinMode(buzzerPin, OUTPUT); 
  // initialize the tilt switch pin as an input:
  pinMode(sigPin, INPUT); 
}
void loop()
{
  // read the state of the tilt switch value:
  digitalWrite(sigPin,LOW);
  sigState = digitalRead(sigPin);
  if (sigState == HIGH)
  { 
    // turn LED on: 
    digitalWrite(buzzerPin,HIGH);
  } 
}
