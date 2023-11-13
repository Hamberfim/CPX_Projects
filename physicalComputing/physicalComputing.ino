// Author: Hamberfim

// include libraries - can include global variables
#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>

// define

// global variables
byte neoState = 0;
byte currentBtnState = 0;
byte lastBtnState = 0;

void setup() {
  // put your setup code here, to run once:
  // init Serial
  Serial.begin(9600);
  // init the CPX and pins/input/output
  CircuitPlayground.begin();
  // All borads have a defined LED_BUILTIN, for CPX it is pin D13
  pinMode(LED_BUILTIN, OUTPUT);  // also known as CPLAY_REDLED on the CPX hardware
  // CPX left builtin push button 'A' - D4 using the pull down resistor
  pinMode(CPLAY_LEFTBUTTON, INPUT_PULLDOWN);   // Button A, also know as CPLAY_LEFTBUTTON. INPUT_PULLDOWN: zero when not pushed, will pull down to 'ground' when pushed
  pinMode(CPLAY_RIGHTBUTTON, INPUT_PULLDOWN);  // Button A, D5
  pinMode(7, INPUT);                           // slide switch
}

void loop() {
  // put your main code here, to run repeatedly:
  // local variables
  const byte delayTime = 50;
  const byte neoPixIndex = 7;

  // logical check if button A is pressed
  if (digitalRead(CPLAY_LEFTBUTTON) == 1) {  // the on/off value, i.e., '0' or '1' is in the global scope because of the included CPX library
    // if pressed toggle-turn on LED
    digitalWrite(LED_BUILTIN, HIGH);
    delay(delayTime);
  } else {
    // if released toggle-turn off LED
    digitalWrite(LED_BUILTIN, LOW);
    delay(delayTime);
  }

  // check if button B is pressed - toggle on and off
  currentBtnState = digitalRead(CPLAY_RIGHTBUTTON);
  if (currentBtnState == 1 && lastBtnState == 0) {
    if (neoState == 0) {
      // if true toggle a neopixel on
      CircuitPlayground.setPixelColor(neoPixIndex, 5, 15, 10);
      neoState = 1;
    } else {
      // if true toggle a neopixel off
      CircuitPlayground.setPixelColor(neoPixIndex, 0, 0, 0);
      neoState = 0;
    }
  }
  lastBtnState = currentBtnState;

// NEXT VIDEO - Analog Programming: https://youtu.be/a6VwfgfSAYQ?list=PLsTszf0qK1ZfgdjqmaZNVwmuH64IZZDa3

  // check the switch state
  if (digitalRead(CPLAY_SLIDESWITCHPIN)) {
    // run a neopixel animations
    for (byte t = 0; t < 4; t++) {       // animate 3 times
      for (byte i = 1; i <= 10; i++) {   // index of neopixel
        for (byte j = 1; j <= i; j++) {  // blink index
          byte randR = random(7, 25);
          byte randG = random(7, 25);
          byte randB = random(7, 25);
          CircuitPlayground.setPixelColor(i - 1, randR, randG, randB);  // start at zero (i-1)
          delay(750 / i);
          CircuitPlayground.setPixelColor(i - 1, 0, 0, 0);
          delay(750 / i);
        }
      }
    }
  }
}
