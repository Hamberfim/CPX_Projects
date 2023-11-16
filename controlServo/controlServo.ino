/***************************************************************
* Name         : simple servo control
* Author       : Anthony Hamlin
* Created      : 11/16/2023
* Version      : 1.0
* OS           : Windows 10
* IDE          : Arduino 2.2.1
* Copyright    : This is my own original work but based on specifications found online
* Description  : Control the servo with the left and right buttons
*                      Input : ?
*                      Output: ?  
***************************************************************/

// libraries
#include <Servo.h>
#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>

// global
Servo myServo;
byte angle = 0;
bool lastUsedD4 = false;
bool lastUsedD5 = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // init device
  CircuitPlayground.begin();
  myServo.attach(10);  // same as A3 but digital

  pinMode(4, INPUT_PULLDOWN);
  pinMode(5, INPUT_PULLDOWN);

  myServo.write(90);
  delay(1000);  // allow setup initialization
}

void loop() {
  // put your main code here, to run repeatedly:

  // see if servo is actually attached
  bool isAttached = myServo.attached();
  Serial.print("Is servo attached: ");
  Serial.print(isAttached);
  Serial.print("\t");

  // left button D4
  if (digitalRead(4) && angle != 0) {
    myServo.write(0);
    lastUsedD4 = true;
    lastUsedD5 = false;
    delay(50);
  } else if (digitalRead(4) && angle == 0 && lastUsedD4) {
    for (byte i = 0; i <= 4; i++) {
      CircuitPlayground.setPixelColor(i, 20, 0, 0);
    }
    for (byte i = 5; i <= 9; i++) {
      CircuitPlayground.setPixelColor(i, 0, 20, 0);
    }
    delay(15);
    CircuitPlayground.playTone(262, 5, false);
  }

  // right button D5
  if (digitalRead(5) && angle != 180) {
    myServo.write(180);
    lastUsedD4 = false;
    lastUsedD5 = true;
    delay(50);
  } else if (digitalRead(5) && angle == 180 && lastUsedD5) {
    for (byte i = 0; i <= 4; i++) {
      CircuitPlayground.setPixelColor(i, 0, 20, 0);
    }
    for (byte i = 5; i <= 9; i++) {
      CircuitPlayground.setPixelColor(i, 20, 0, 0);
    }
    delay(15);
    CircuitPlayground.playTone(262, 5, false);
  }

  // current angle location
  angle = (byte)myServo.read();
  Serial.print("What is current angle: ");
  Serial.println(angle);
}
