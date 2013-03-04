// Concentric Squares

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

  // one line at a time, getting smaller
  for (int r = 4; r > 0; r--) {
    int pos = 4 - r;
    int width = r * 2;
    matrix.drawRect(pos, pos, width, width, LED_RED);
    matrix.writeDisplay();
    delay(200);
    matrix.clear();
  }

   matrix.writeDisplay();

  // filling in, getting smaller
  for (int r = 1; r < 5; r++) {
    int pos = 4 - r;
    int width = r * 2;
    matrix.drawRect(pos, pos, width, width, LED_RED);
    matrix.writeDisplay();
    delay(200);
  }

  matrix.clear();

  // filling in, getting smaller
  for (int r = 4; r > 0; r--) {
    int pos = 4 - r;
    int width = r * 2;
    matrix.drawRect(pos, pos, width, width, LED_RED);
    matrix.writeDisplay();
    delay(200);
  }

  matrix.clear();

}
