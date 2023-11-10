// Ghost Popsicle - basic tutorial via Jason Shine:
// 1. https://youtu.be/HhFiWmDMbVA
// 2. https://youtu.be/SrUlv1ExcWY
// 3. https://youtu.be/bwHrBlprIro

// Author of revisions & refactoring - Hamberfim

// Libraries
#include <Adafruit_CircuitPlayground.h>  // searches default library location

void setup() {
  // put your setup code here, to run once:
  // init serial monitor
  Serial.begin(9600);
  // initialize the Circuit Playground Express (CPX) device
  CircuitPlayground.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  // blinkLed(); // function to blink builtin led at pin D13
  // lightAllPixels(255, 0, 0);  function turns on all neopixels via RGB input values
  // cyclePixelsRGB(500);  // input is the delay time between changes, changes all neopixels to red then green then blue in a loop cycle
  // fadeInRed();
  // readLtTpValues();
  readSensorValues();
}

void readSensorValues() {
  byte delayTime = 100;

  Serial.print("Light: ");
  Serial.print(CircuitPlayground.lightSensor());
  Serial.print(" | Sound: ");
  Serial.print(CircuitPlayground.mic.soundPressureLevel(25));
  Serial.print(" | xTilt: ");
  Serial.print(CircuitPlayground.motionX());
  Serial.print(" | yTilt: ");
  Serial.print(CircuitPlayground.motionY());
  Serial.print(" | zTilt: ");
  Serial.print(CircuitPlayground.motionZ());
  Serial.print(" | Temperature: ");
  Serial.println(CircuitPlayground.temperatureF());

  delay(delayTime * 50);
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