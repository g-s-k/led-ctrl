#include "Adafruit_NeoPixel.h"

#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 9

#define NUM_LEDS 240

#define BRIGHTNESS 30

#define PERIOD 20

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

}

void loop() {
  for(uint16_t j=0; j<strip.numPixels(); j++) {
    strip.setPixelColor(j, Wheel(((j * 256 / strip.numPixels()) + millis() / PERIOD) & 255));
  }
  strip.show();
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3,0);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3,0);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0,0);
}

