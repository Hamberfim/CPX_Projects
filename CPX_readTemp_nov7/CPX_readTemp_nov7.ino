#include <Adafruit_CircuitPlayground.h>  // probably the newer lib
// #include <Adafruit_Circuit_Playground.h>

// blynk conn
#define BLYNK_TEMPLATE_ID "TMPL2n5LkV5zJ"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "YAOCrDsx66M-Zf-RnaUs4qgmhg4pQ-2C"
#define WIFI_SSID ""
#define WIFI_PASS ""

// variables
float tempValueC, tempValueF;
uint8_t brightness = 5;

// The setup function runs once when you press reset or power the board
void setup() {
  // initialization
  Serial.begin(9600);  // open serial connection at 9600 bps

  // init CPE library
  CircuitPlayground.begin(brightness);
}

// The loop function runs over and over again forever
void loop() {
  tempValueF = CircuitPlayground.temperatureF();  // get the sensor value in Fahrenheit
  tempValueC = CircuitPlayground.temperature();   // celcius
  Serial.print("Temp. F: ");                      // output title
  Serial.println(tempValueF);                     // output value

  Serial.print("Temp. C: ");   // output title
  Serial.println(tempValueC);  // output value

  if (tempValueF >= 70.00 && tempValueF <= 81.99) {
    CircuitPlayground.setPixelColor(9, 0, 255, 0);  // green
    Serial.println("GREEN <= 81.99F");
  } else if (tempValueF > 81.99 && tempValueF <= 111) {
    CircuitPlayground.setPixelColor(9, 255, 0, 0);  // red
    Serial.println("RED >= 82.00");
  } else {
    CircuitPlayground.setPixelColor(9, 0, 0, 0);
    Serial.println("UNKNOWN either below 70F or over 111F");
  }

  Serial.println();
  delay(10000);
}
