/***************************************************************
* Name         : pcAdvanceAnalog
* Author       : Anthony Hamlin
* Created      : 11/15/2023
* Version      : 1.0
* OS           : Windows 10
* IDE          : Arduino 2.2.1
* Copyright    : This is my own original work but based on specifications found online
* Description  : Read the accelerometer x and y sensors abd change the neopixels based on their values
*                      Input : ?
*                      Output: ?  
***************************************************************/

// libraries
#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>
#include <math.h>

// global variables


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  CircuitPlayground.begin();

  delay(1000);  // wait for intialization of setup
}

void loop() {
  // put your main code here, to run repeatedly:

  // read the accelerometer x and y values
  float xTilt = CircuitPlayground.motionX();
  float yTilt = CircuitPlayground.motionY();
  float radiansDegReading = atan2(yTilt, xTilt);                      // arc tangent
  int neopixelNumber = mapFloat(radiansDegReading, -PI, PI, -1, 10);  // customize the map so it uses float values instead of truncating the decimal when cast to int
  neopixelNumber -= 2;                                                // adjust the index position so the values fall/better align with the neopixels and the tilt
  if (neopixelNumber < 0) neopixelNumber += 10;

  // output readings
  Serial.print(xTilt);
  Serial.print("\t");
  Serial.print(yTilt);
  Serial.print("\t");
  Serial.print(radiansDegReading);
  Serial.print("\t");
  Serial.println(neopixelNumber);

  byte red = 0;
  byte green = 0;
  byte blue = 0;

  // if (neopixelNumber >= 0 && neopixelNumber <= 2) {
  //   red = 0;
  //   green = 0;
  //   blue = 30;
  // } else if (neopixelNumber > 2 && neopixelNumber <= 5) {
  //   red = 0;
  //   green = 30;
  //   blue = 0;
  // } else if (neopixelNumber >= 6 && neopixelNumber <= 9) {
  //   red = 30;
  //   green = 0;
  //   blue = 0;
  // }

  // change color of pixels based on x/y values using a builtin function from the math library
  CircuitPlayground.clearPixels();
  // CircuitPlayground.setPixelColor(neopixelNumber, red, green, blue);
  CircuitPlayground.setPixelColor(neopixelNumber, 55, 0, 0);
  delay(25);

  // end of file
}

float mapFloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
