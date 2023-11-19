/***************************************************************
* Name         : Capacitive Touch on the Circuit Playground Express
* Author       : Anthony Hamlin
* Created      : 11/17/2023
* Version      : 1.0
* OS           : Windows 10
* IDE          : Arduino 2.2.1
* Copyright    : This is my own original work but based on specifications found online
* Description  : Capacitive touch sensing demo
*                      Input : Touch pins A1-A7
*                      Output: a NeoPixel 1-7  
***************************************************************/
// included libraries
#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>

// global variables
int threshold = 400;  // this is set based on the readings
byte debounce = 100;   // delay response


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  CircuitPlayground.begin();

  delay(1000);  // wait till setup has initialized
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int pin = A1; pin <= A7; pin++) {
    int touchPin = CircuitPlayground.readCap(pin);
    if (touchPin < threshold) {
      CircuitPlayground.setPixelColor(pin - 14, 0, 0, 0);
    } else {
      CircuitPlayground.setPixelColor(pin - 14, 0, 0, 30);
    }
    Serial.print(touchPin);
    Serial.print("\t");
  }
  Serial.println();
  delay(debounce);

  // end of file
}
