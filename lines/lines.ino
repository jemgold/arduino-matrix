// Scrolling Lines

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();

int colors[] = {LED_RED, LED_GREEN, LED_YELLOW, LED_RED, LED_YELLOW};

void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");

  matrix.begin(0x70);  // pass in the address
  matrix.setRotation(0);
}

void loop() {

  matrix.clear();
  rightToLeft(1);
  matrix.clear();
  rightToLeft(2);
  matrix.clear();
  rightToLeft(3);

}

void rightToLeft(int i) {
  for(int8_t y=0; y < 8; y++) {
    for(int8_t x=0; x < 8; x++) {
      matrix.drawPixel(x, y, i);
      matrix.writeDisplay();
      delay(30);
    }
  }
}
