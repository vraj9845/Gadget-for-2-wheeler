
//(Burn heater coil of mq-2 before 20 minutes by running the audino or try to check the mq-2 to see if it is warm to use it.)
//(If you know the maximum or minimum range of the actual sensor, then map the value (or try doing one round of simulation to find the minimum or maximum).)
//(And the value has been adjusted. To control the brightness of the led.)

#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX  for bluetooth hc05

// Analog pin 0 will be called 'sensor'
int sensor = A0;
// Set the initial sensorValue to 0
int sensorValue = 0;

// The setup routine runs once when you press reset
void setup() {

  mySerial.begin(9600);    // Initialize software serial communication for hc05
  Serial.begin(9600);   // Initialize serial communication at 9600 bits per second
}

// The loop routine runs over and over again forever
void loop() {
  // Read the input on analog pin 0 (named 'sensor')
  sensorValue = analogRead(sensor);
  //int outputvalue = map(sensorValue, 0, 1023, 0, 255);
  //int outputMap2 = 0;
  //int outputBuzzer = 0;

  if (sensorValue > 280) {
    // Activate digital output pin 9 - the LED will light up
    //Notice the value of the experiment. Minimum =70 , maximum= 110 for my mq2 device
    //outputMap2 = map(outputvalue, 70, 110, 0, 255); // for led,'map' func  from 70-110 become  0-255 so that  be value for pwm made fade with led.
    //map อีกครั้ง 29-110 ไป 0-255  so that pwm ทำ fade กับ led
    //outputMap2 = constrain(outputMap2, 0, 255); //value for led ,  make 'map' func  again,make a wider range of led or brightness of the led. 
    //ทำให้ เห็น ช่วงที่กว้างขึ้นของ  แสง led หรือความสว่างของ led ให้ชัดเจนขึ้น
    //outputBuzzer = 254 - map(outputvalue, 70, 110, 50, 254); //value for buzzer
    //analogWrite(pin9, outputMap2);
    //beep(outputBuzzer);
    mySerial.print(sensorValue);
  }
  else {

    //analogWrite(pin9, 0);
    mySerial.print(sensorValue);
  }

  //for debug  mq2 sensor value
  Serial.print("sensorValue : ");
  Serial.print(sensorValue);
  Serial.println();
  //Serial.print("\t mapValue : ");
 // Serial.print(outputvalue, DEC);
  //Serial.print("\t outputMap2 : ");
  //Serial.println(outputMap2, DEC);
  delay(250);
}
