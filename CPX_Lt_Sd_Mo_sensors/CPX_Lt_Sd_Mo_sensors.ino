// Author: Hamberfim

// Libraries to include
#include <Adafruit_CircuitPlayground.h>  // searches default library location

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  readSensorValues();
}

static void readSensorValues() {
  // use local variables
  byte delayTime = 1000;
  byte soundPressureLimit = 25;

  // Serial.print(F("Light: "));
  // Serial.print(CircuitPlayground.lightSensor());
  // Serial.print(F(", "));

  // Serial.print(F("Sound: "));
  // Serial.print(CircuitPlayground.mic.soundPressureLevel(soundPressureLimit));
  // Serial.print(F(", "));

  // Serial.print(F("xTilt: "));
  // Serial.print(CircuitPlayground.motionX());
  // Serial.print(F(", "));

  // Serial.print(F("yTilt: "));
  // Serial.print(CircuitPlayground.motionY());
  // Serial.print(F(", "));

  // Serial.print(F("zTilt: "));
  // Serial.print(CircuitPlayground.motionZ());
  // Serial.print(F(", "));

  // Serial.print(F("Temperature: "));
  // Serial.println(CircuitPlayground.temperatureF());

  // concat above for output
  String catOutput = "Light: ";
  catOutput.concat(CircuitPlayground.lightSensor());
  catOutput.concat(" Sound: ");
  catOutput.concat(CircuitPlayground.mic.soundPressureLevel(soundPressureLimit));
  catOutput.concat(" xTilt: ");
  catOutput.concat(CircuitPlayground.motionX());
  catOutput.concat(" yTilt: ");
  catOutput.concat(CircuitPlayground.motionY());
  catOutput.concat(" zTilt: ");
  catOutput.concat(CircuitPlayground.motionZ());
  catOutput.concat(" Temperature: ");
  catOutput.concat(CircuitPlayground.temperatureF());
  Serial.println(catOutput);

  delay(delayTime);
}