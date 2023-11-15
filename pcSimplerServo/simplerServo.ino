// Author: Hamberfim

// libraries
#include <Servo.h>
#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>

// global
Servo myServo;
byte position = 0;
byte increment = 1;
long timer = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // init device
  CircuitPlayground.begin();
  myServo.attach(10);  // same as A3 but digital
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(4, INPUT_PULLDOWN);

  delay(1000);  // allow setup initialization
}

void loop() {
  // put your main code here, to run repeatedly:

  // ==== v3 using a time variable
  if (millis() > timer + 15) {  // millis() counts the elapsed time - potetial to run out of mem space in millis() after 48 days
    if (position == 0) {
      increment = 1;
    } else if (position == 180) {
      increment = -1;
    }
    myServo.write(position);
    position += increment;
    timer = millis();
  }

  // ==== v2 appears to be non blocking but is acctuall just super fast ====
  // if (position == 0) {
  //   increment = 1;
  // } else if (position == 180) {
  //   increment = -1;
  // }
  // myServo.write(position);
  // position += increment;
  // delay(15);

  /* ==== v1 loop interups digitalWrite/Read because of 'delay()' ==== */
  // for (byte i = 0; i <= 180; i++) {
  //   myServo.write(i);
  //   delay(15);
  // }

  // for (byte i = 180; i <= 0; i--) {
  //   myServo.write(i);
  //   delay(15);
  // }

  digitalWrite(LED_BUILTIN, digitalRead(4));  // turn the light on when pushing the D4 button (left)
  // blocks
  if (digitalRead(4)) CircuitPlayground.playTone(262, 5, false);  // false is suppose to set it to non-blocking but doesn't work so short duration fakes non-blocking
}
