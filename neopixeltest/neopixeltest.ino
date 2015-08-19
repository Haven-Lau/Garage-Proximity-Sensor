#include <Adafruit_NeoPixel.h>

#define PIN 6
#define LEDNUM 30
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDNUM, PIN, NEO_GRB + NEO_KHZ800);
int number = 0;
void setup() {
  strip.begin();
  Serial.begin(115200);
  strip.setBrightness(50);
  strip.show(); // Initialize all pixels to 'off'
}
void loop(){

  for (int i = 0; i < LEDNUM; i++){
    strip.setPixelColor(i, 0, 50, 50);
    strip.show();
    delay(500);
  }
  for (int i = 0; i < LEDNUM; i++){
    strip.setPixelColor(i, 0, 0, 0);
    strip.show();
    delay(500);
  }
}
