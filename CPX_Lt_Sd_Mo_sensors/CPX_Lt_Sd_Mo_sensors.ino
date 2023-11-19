/***************************************************************
* Name         : CPX_Lt_Sd_Mo_sensors
* Author       : Anthony Hamlin
* Created      : 11/17/2023
* Version      : 1.0
* OS           : Ubuntu 22.04
* IDE          : Arduino 2.2.1
* Copyright    : This is my own original work but based on specifications found online
* Description  : Uses the light, sound, motion sensors and outputs them to the serial monitor
*                      Input : Sensor data
*                      Output: Serial Monitor or Plotter (uncomment specific code) 
***************************************************************/
// included libraries searches default library location
#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  readSensorValues();  // call function
}

static void readSensorValues() {
  // use local variables
  int delayTime = 1000;
  int soundPressureLimit = 25;

  /* This section used for plotting */
  // Serial.print(F("Light: "));
  Serial.print(CircuitPlayground.lightSensor());  // Value 1
  Serial.print(F(", "));

  // Serial.print(F("Sound: "));
  Serial.print(CircuitPlayground.mic.soundPressureLevel(soundPressureLimit));  // Value 2
  Serial.print(F(", "));

  // Serial.print(F("xTilt: "));
  Serial.print(CircuitPlayground.motionX());  // Value 3
  Serial.print(F(", "));

  // Serial.print(F("yTilt: "));
  Serial.print(CircuitPlayground.motionY());  // Value 4
  Serial.print(F(", "));

  // Serial.print(F("zTilt: "));
  Serial.print(CircuitPlayground.motionZ());  // Value 5
  Serial.print(F(", "));

  // Serial.print(F("Temperature: "));
  Serial.println(CircuitPlayground.temperatureF());  // Value 6

  /* This section used for serial monitor output */
  // concatination for output
  // String catOutput = "Light: ";
  // catOutput.concat(CircuitPlayground.lightSensor());
  // catOutput.concat(" Sound: ");
  // catOutput.concat(CircuitPlayground.mic.soundPressureLevel(soundPressureLimit));
  // catOutput.concat(" xTilt: ");
  // catOutput.concat(CircuitPlayground.motionX());
  // catOutput.concat(" yTilt: ");
  // catOutput.concat(CircuitPlayground.motionY());
  // catOutput.concat(" zTilt: ");
  // catOutput.concat(CircuitPlayground.motionZ());
  // catOutput.concat(" Temperature: ");
  // catOutput.concat(CircuitPlayground.temperatureF());
  // Serial.println(catOutput);

  delay(delayTime);
}