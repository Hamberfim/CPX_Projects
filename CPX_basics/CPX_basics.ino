// Ghost Popsicle - basic tutorial via Jason Shine:
// 1. https://youtu.be/HhFiWmDMbVA
// 2. https://youtu.be/SrUlv1ExcWY
// 3. https://youtu.be/bwHrBlprIro

// Author of revisions & refactoring - Hamberfim

// Libraries
#include <Adafruit_CircuitPlayground.h>  // searches default library location
#include "pitches.h"

void setup() {
  // put your setup code here, to run once:
  // init serial monitor
  Serial.begin(9600);
  // initialize the Circuit Playground Express (CPX) device
  CircuitPlayground.begin();

  // init left builtin button A/D4
  pinMode(CPLAY_LEFTBUTTON, INPUT_PULLDOWN);
  // init right builtin button B/D5
  pinMode(CPLAY_RIGHTBUTTON, INPUT_PULLDOWN);
}

void loop() {
  // put your main code here, to run repeatedly:
  // blinkLed(); // function to blink builtin led at pin D13
  // lightAllPixels(255, 0, 0);  function turns on all neopixels via RGB input values
  // cyclePixelsRGB(500);  // input is the delay time between changes, changes all neopixels to red then green then blue in a loop cycle
  // fadeInRed();
  // readLtTpValues();
  // plotSensorValues();
  // readSensorValues();
  // testSound();
  // climbingSound();
  // fallingSound();
  // majorScale();
  // tiltPitch();
  // buttonsPlaySounds();
  buttonsChoiceSounds();
}

void buttonsChoiceSounds() {
  byte delayTime = 500;
  // check if a button is pushed
  if (digitalRead(CPLAY_LEFTBUTTON)) {
    tiltPitch();
  } else if (digitalRead(CPLAY_RIGHTBUTTON)) {
    majorScale();
  }
}

void buttonsPlaySounds() {
  byte delayTime = 500;
  // check if a button is pushed
  if (digitalRead(CPLAY_LEFTBUTTON)) {
    lightAllPixels(255, 0, 0);
    climbingSound();
    delay(delayTime);
    lightAllPixels(0, 255, 0);
    delay(delayTime);
    lightAllPixels(0, 0, 255);
    delay(delayTime);
    lightAllPixels(0, 0, 0);
  } else if (digitalRead(CPLAY_RIGHTBUTTON)) {
    lightAllPixels(0, 0, 255);
    fallingSound();
    delay(delayTime);
    lightAllPixels(0, 255, 0);
    delay(delayTime);
    lightAllPixels(255, 0, 0);
    delay(delayTime);
    lightAllPixels(0, 0, 0);
  }
}

void tiltPitch() {
  byte delayTime = 50;
  int beepPitch = map(CircuitPlayground.motionX(), -10, 10, 500, 1500);  // -10 to 10 is the tilt, 500 to 1500 is the sound pitch frequency
  CircuitPlayground.playTone(beepPitch, delayTime);
}

void majorScale() {
  byte delayTime = 100;
  byte noteLength = 50;
  CircuitPlayground.playTone(NOTE_C4, noteLength);
  delay(delayTime);
  CircuitPlayground.playTone(NOTE_D4, noteLength);
  delay(delayTime);
  CircuitPlayground.playTone(NOTE_E4, noteLength);
  delay(delayTime);
  CircuitPlayground.playTone(NOTE_F4, noteLength);
  delay(delayTime);
  CircuitPlayground.playTone(NOTE_G4, noteLength);
  delay(delayTime);
  CircuitPlayground.playTone(NOTE_A4, noteLength);
  delay(delayTime);
  CircuitPlayground.playTone(NOTE_B4, noteLength);
  delay(delayTime);
  CircuitPlayground.playTone(NOTE_C5, noteLength);
  delay(delayTime);
}

void fallingSound() {
  byte delayTime = 3;
  byte increment = 100;
  byte noteLength = 50;
  int noteFreqStart = 1000;  // 40-1800 within human range while not extremely annoying
  byte noteFreqMin = 40;

  for (int i = noteFreqStart; i >= noteFreqMin; i -= increment) {
    CircuitPlayground.playTone(i, noteLength);
    delay(delayTime);
  }
  // delay(3000);
}


void climbingSound() {
  byte delayTime = 3;
  byte increment = 100;
  byte noteLength = 50;
  byte noteFreqStart = 40;  // 40-1800 within human range while not extremely annoying
  int noteFreqMax = 1000;

  for (int i = noteFreqStart; i <= noteFreqMax; i += increment) {
    CircuitPlayground.playTone(i, noteLength);
    delay(delayTime);
  }
  // delay(3000);
}

void testSound() {
  byte delayTime = 100;
  byte noteLength = 125;
  byte freqSound = 110;
  CircuitPlayground.playTone(freqSound, noteLength);  // lower octive of middle A on a piano, 110 hertz. at 125 miliseonds
  delay(delayTime);
  CircuitPlayground.playTone(freqSound * 2, noteLength);  // lower octive of middle A on a piano, 220 hertz. at 125 miliseonds
  delay(delayTime);
  CircuitPlayground.playTone(freqSound * 4, noteLength);  // middle A on a piano, 440 hertz. at 125 miliseonds
  delay(delayTime);
  CircuitPlayground.playTone(freqSound * 8, noteLength);  // octive of middle A on a piano, 880 hertz. at 125 miliseonds
  delay(delayTime);
  CircuitPlayground.playTone(freqSound * 16, noteLength);  // octive of middle A on a piano, 1760 hertz. at 125 miliseonds
  delay(delayTime);
}

void readSensorValues() {
  byte delayTime = 50;

  Serial.print(F("Light: "));
  Serial.print(CircuitPlayground.lightSensor());

  Serial.print(F(" | Sound: "));
  Serial.print(CircuitPlayground.mic.soundPressureLevel(25));

  Serial.print(F(" | xTilt: "));
  Serial.print(CircuitPlayground.motionX());

  Serial.print(F(" | yTilt: "));
  Serial.print(CircuitPlayground.motionY());

  Serial.print(F(" | zTilt: "));
  Serial.print(CircuitPlayground.motionZ());

  Serial.print(F(" | Temperature: "));
  Serial.println(CircuitPlayground.temperatureF());

  delay(delayTime);
}

void plotSensorValues() {
  byte delayTime = 100;
  // light sensor
  Serial.print(CircuitPlayground.lightSensor());  // value 1 on the plotter
  Serial.print(" ");                              // so the plotter can see each sesor data being read

  // sound sensor
  Serial.print(CircuitPlayground.mic.soundPressureLevel(25));
  Serial.print(" ");

  // xTilt sensor
  Serial.print(CircuitPlayground.motionX());
  Serial.print(" ");

  // yTilt sensor
  Serial.print(CircuitPlayground.motionY());
  Serial.print(" ");

  // zTilt sensor
  Serial.print(CircuitPlayground.motionZ());
  Serial.print(" ");

  // temperature sensor
  Serial.println(CircuitPlayground.temperatureF());
  delay(delayTime * 20);
}

void readLtTpValues() {
  int delayTime = 1000;

  // String newLineReturn = "\n";
  // // create label with concatenated int light sensor value
  // String sensorsDisplay = "Light: ";                 // create a text label
  // int lightValue = CircuitPlayground.lightSensor();  // read the sensor value
  // sensorsDisplay.concat(lightValue);                 // join the label and the value  i.e., "Light: 85"
  // sensorsDisplay.concat(newLineReturn);              // add a new line return

  // // create label with concatenated int temperature sensor value
  // String temperatureLabel = "Temperature: ";                // create a text lable
  // sensorsDisplay.concat(temperatureLabel);                  // join the label to the above concatenation
  // int temperatureValue = CircuitPlayground.temperatureF();  // read the sensor value
  // sensorsDisplay.concat(temperatureValue);                  // join the value to the existing concatenation
  // Serial.println(sensorsDisplay);  // send to serial monitor
  // delay(delayTime * 2);

  // above simplified
  String lightLable = "Light: ";
  int lightValue = CircuitPlayground.lightSensor();  // read the sensor value

  String temperatureLabel = "Temperature: ";                // create a text lable
  int temperatureValue = CircuitPlayground.temperatureF();  // read the sensor value

  // concatenation
  auto displayReading = lightLable + lightValue + "\n" + temperatureLabel + temperatureValue + "\n";  // auto concatenation instead of calling .concate()
  Serial.println(displayReading);

  delay(delayTime * 2);
}

void fadeInRed() {
  byte delayTime = 10;
  for (byte i = 0; i <= 255; i++) {
    lightAllPixels(i, 0, 0);
    delay(delayTime);
  }
  delay(delayTime * 12.5);
}

void cyclePixelsRGB(int delayTime) {
  lightAllPixels(255, 0, 0);  // function to light up all 9 neopixels
  delay(delayTime);
  lightAllPixels(0, 255, 0);  // function to light up all 9 neopixels
  delay(delayTime);
  lightAllPixels(0, 0, 255);  // function to light up all 9 neopixels
  delay(delayTime);
}

// a byte can be 0-255 in value
void lightAllPixels(byte red, byte green, byte blue) {
  for (byte i = 0; i <= 9; i++) {
    CircuitPlayground.setPixelColor(i, red, green, blue);  // pixel light value
  }
}

void blinkLed() {
  int delayValue = 250;  // time in miliseconds
  CircuitPlayground.redLED(true);
  delay(delayValue);
  CircuitPlayground.redLED(false);
  delay(delayValue);
}