// Author: Hamberfim

// included libraries
#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>


void setup() {
  // put your setup code here, to run once:
  // init Serial
  Serial.begin(9600);

  // init the CPX and pins/input/output
  CircuitPlayground.begin();
  // All borads have a defined LED_BUILTIN, for CPX it is pin D13
  pinMode(LED_BUILTIN, OUTPUT);  // also known as CPLAY_REDLED on the CPX hardware
}

void loop() {
  // put your main code here, to run repeatedly:
  // ===== analog light sensor range - 10bit- values range between 0-1023 =====
  // read analog sensor - photo light sensor
  int lightValue = analogRead(A8);

  // set constants for min-max value range of the analog 10bit light sensor
  byte lowEnd = 0;     // min values of sensor reading
  int highEnd = 1023;  // max values of sensor reading
  // set constants for the min-max scale-down range for 8bit output
  byte lowScaleRange = 0;     // min scale down the reading
  byte highScaleRange = 255;  // max scale down the reading

  // map the analog light sensor value from 10bit down to 8bit - down-scale the light reading value to analogWrite range of the LED
  byte brightnessLevel = map(lightValue, lowEnd, highEnd, lowScaleRange, highScaleRange);  // get brighter the lighter it is
  // byte brightnessLevel = map(lightValue, lowEnd, highEnd, highScaleRange, lowScaleRange);  // get brighter the darker it is

  Serial.print(lightValue);  // the reading value
  Serial.print("\t");
  Serial.print(brightnessLevel);  // the down-scaled value
  Serial.print("\t");
  delay(500);

  // set the brightness of the an LED
  // analogWrite(LED_BUILTIN, brightnessLevel);

  // read accelerometer
  float xTilt = CircuitPlayground.motionX();
  float yTilt = CircuitPlayground.motionY();
  Serial.print(xTilt);
  Serial.print("\t");
  Serial.print(yTilt);
  Serial.print("\t");

  // change color of neopixels
  byte r = map(xTilt, -10, 10, 0, 255);
  byte b = map(yTilt, -10, 10, 0, 255);

  Serial.print(r);
  Serial.print("\t");
  Serial.print(b);
  Serial.print("\t");

  for (byte i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, r, 0, b);
  }

  // mic
  float micSoundPressureLv = CircuitPlayground.mic.soundPressureLevel(100);
  Serial.println(micSoundPressureLv);
}
