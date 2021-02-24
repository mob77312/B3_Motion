/**************************************************************
 * IoT Motion Detector with Blynk
 * Blynsk library is licensed under MIT license
 * This example code is in public domain.
 * 
 * Developed by Marcelo Rovai - 30 November 2016
 **************************************************************/
#include <ESP8266WiFi.h>
//
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <BlynkSimpleEsp8266.h>
char auth[] = "w60YVxH8ZIqoPLkHIWcEz9-PfgH4qtQI";
////A--WzidmJ3dXxXsI-M5umW_ui76-Cwz3
///* WiFi credentials */
char ssid[] = "Jerrycho";
char pass[] = "buncis77312";
//
///* HC-SR501 Motion Detector */
#define ledPin D7 
#define pirPin D1 // Input for HC-S501
int pirValue; // Place to store read PIR Value
int count = 0,count1 = 0;

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  digitalWrite(ledPin, LOW);
}

void loop()
{
  pirValue = digitalRead(pirPin);
  if (pirValue) 
  { 
    
    digitalWrite(ledPin, HIGH);
    count++;
    if (count == 1)
    {
    count1 = count1 + count;
    count = 0;
    digitalWrite(ledPin, LOW);
    }
    Serial.println(count1);
    Blynk.notify(count1);  
    
  }
  else {
    digitalWrite(ledPin, pirValue);
    Serial.println("Not Detected");
  }

  Blynk.run();
}

//#define ledPin D7 // Red LED
//#define pirPin D1 // Input for HC-SR501
//
//int pirValue; // variable to store read PIR Value
//int count = 0;
//int count1 = 0;
//
//void setup() 
//{
//  Serial.begin(115200);
//  delay(1000);
//  pinMode(ledPin, OUTPUT);
//  pinMode(pirPin, INPUT);
//  digitalWrite(ledPin, LOW);
//}
//
//void loop() 
//{
//  if (pirValue) 
//  { 
//    count++;
//    if (count == 1)
//    {
//    count1 = count1 + count;
//    count = 0;
//    }
//    Serial.println(count1);
//  }
//  digitalWrite(ledPin, pirValue);
//}




//int ledPin = 13; // choose the pin for the LED
//int inputPin = 3; // choose the input pin (for PIR sensor)
//int pirState = LOW; // we start, assuming no motion detected
//int val = 0; // variable for reading the pin status
//int counter = 0;
//int currentState = 0;
//int previousState = 0;
//void setup() {
//  pinMode(ledPin, OUTPUT); // declare LED as output
//  pinMode(inputPin, INPUT); // declare sensor as input
//  Serial.begin(9600);
//}
//void loop() {
//  val = digitalRead(inputPin); // read input value
//  if (val == HIGH) { // check if the input is HIGH
//    digitalWrite(ledPin, HIGH); // turn LED ON
//    if (pirState == LOW) {
//      // we have just turned on
//      currentState = 1;
//      // We only want to print on the output change, not state
//      pirState = HIGH;
//      delay(1000);
//    }
//  } else {
//    digitalWrite(ledPin, LOW); // turn LED OFF
//    if (pirState == HIGH) {
//      // we have just turned of
//      currentState = 0;
//      // We only want to print on the output change, not state
//      pirState = LOW;
//    }
//  }
//  if (currentState != previousState) {
//    if (currentState == 1) {
//      counter = counter + 1;
//      Serial.println(counter);
//    }
//  }
//}
