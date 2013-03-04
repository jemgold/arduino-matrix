// Crazy Scrolling Lines

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();

int speed = 20;
int speedInc = 20;

void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");

  matrix.begin(0x70);  // pass in the address
  matrix.setRotation(0);
}

void loop() {
  drawLines(speed);

  if (speed == 200 || speed == 20) {
    speedInc = -speedInc;
  }
  speed = speed + speedInc;
}

void drawLines(int speed) {
  for (int8_t i = 0; i < 8; i++) {
    // for some reason I need to turn off LEDs before turning them on WTF
    matrix.drawLine(i,0, i, 7, LED_OFF);
    matrix.drawLine(i,0, i, 7, LED_RED);

    int j;
    if ((i-2) < 0) {
      j = (i - 2 + 8);
    } else {
      j = (i - 2);
    }

    matrix.drawLine(j,0, j,7, LED_OFF);
    matrix.drawLine(j,0, j,7, LED_YELLOW);

    int k;
    if ((i-4) < 0) {
      k = (i - 4 + 8);
    } else {
      k = (i - 4);
    }

    matrix.drawLine(k,0, k,7, LED_OFF);
    matrix.drawLine(k,0, k,7, LED_GREEN);

    int l;
    if ((i-6) < 0)  {
      l = (i - 6 + 8);
    } else {
      l = (i - 6);
    }

    matrix.drawLine(l,0, l,7, LED_OFF);

    matrix.writeDisplay();
    delay(speed);
  }
}
