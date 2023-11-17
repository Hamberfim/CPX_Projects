/***************************************************************
* Name         : Data Smoothing on the Circuit Playground Express
* Author       : Anthony Hamlin
* Created      : 11/17/2023
* Version      : 1.0
* OS           : Windows 10
* IDE          : Arduino 2.2.1
* Copyright    : This is my own original work but based on specifications found online
* Description  : How to smooth out data that veries widely.
*                      Input : ?
*                      Output: ?  
***************************************************************/
// included libraries
#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>

// global variables

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  CircuitPlayground.begin();
  delay(1000);  // wait for setup to initialize
}

void loop() {
  // put your main code here, to run repeatedly:
  int lightSensorReading = analogRead(A8);
  Serial.print("Lt Reading: ");
  Serial.print(lightSensorReading);  // read the analog light sensor
  Serial.print("\t");

  int numSampleReads = 10;  // number of samples to read
  int sensorSum = 0;       // sum of the sensor sample readings

  for (int i = 0; i < numSampleReads; i++) {
    sensorSum += lightSensorReading;
    delay(1);
  }
  Serial.print("Sensor Sum: ");
  Serial.print(sensorSum);
  Serial.print("\t");

  int sensorAverage = sensorSum / numSampleReads;  // get an average of the sensor readings to smooth the data
  Serial.print("Sensor Avg: ");
  Serial.print(sensorAverage);
  Serial.print("\t");

  byte sensorReadingsToPixels = map(sensorAverage, 0, 1023, 0, 255);
  Serial.print("Mapped down: ");
  Serial.println(sensorReadingsToPixels);

  byte r = 0;
  byte g = 0;
  byte b = 0;
  for (byte i = 0; i <= 9; i++) {
    if (sensorReadingsToPixels <= 80) {
      g = sensorReadingsToPixels;
    } else if (sensorReadingsToPixels > 80 && sensorReadingsToPixels <= 160) {
      b = sensorReadingsToPixels;
      r = 25;
    } else {
      r = sensorReadingsToPixels;
    }
    CircuitPlayground.setPixelColor(i, r, g, b);
  }
  delay(200);

  // end of file
}
