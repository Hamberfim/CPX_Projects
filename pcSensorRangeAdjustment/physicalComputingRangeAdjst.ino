// Author: Hamberfim

// included libraries
#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>

// global vars
// dynamic range adjustment for analog sensors
int minPhVal = 500;
int maxPhVal = 500;

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
  int photoValue = analogRead(A8);  // pass the light sensor reading to another variable
  delay(500);
  Serial.print("base photo val: ");
  Serial.print(photoValue);

  // dynamic range adjustment for analog sensors
  if (photoValue < minPhVal) {
    minPhVal = photoValue;
  }
  if (photoValue > maxPhVal) {
    maxPhVal = photoValue;
  }
  byte mapVal = map(photoValue, minPhVal, maxPhVal, 0, 255);
  Serial.print(" as mapped val: ");
  Serial.println(mapVal);
  analogWrite(LED_BUILTIN, mapVal);
}
