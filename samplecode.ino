#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(numPixels, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  strip.setPixelColor(0,0,0,255);
  strip.show();
  delay(100);
  strip.setPixelColor(0,0,255,0);
  strip.show();
  delay(100);
}

