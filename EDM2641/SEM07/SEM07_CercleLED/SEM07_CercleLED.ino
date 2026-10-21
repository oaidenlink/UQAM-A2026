#include <Adafruit_NeoPixel.h>

int nbOfLeds = 16;
int pinLeds = 5;
Adafruit_NeoPixel belles_Leds(nbOfLeds, pinLeds, NEO_GRB + NEO_KHZ800);

void setup() {
  belles_Leds.begin();
  belles_Leds.clear();
}

// void loop() {
//   belles_Leds.setPixelColor(3,255,0,0);
//   belles_Leds.show();
//   delay(100);

//   belles_Leds.setPixelColor(3,0,0,255);
//   belles_Leds.show();
//   delay(1000);
// }

//////////////////////////////////////////////////////////////////////

void loop() {
  int led = random(0,16);
  int r = random(0,10);
  int g = random(0,10);
  int b = random(0,10);

  belles_Leds.setPixelColor(led,r,g,b);
  belles_Leds.show();
  delay(10);
}