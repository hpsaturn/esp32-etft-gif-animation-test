
#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include <sleep.hpp>
#include "animation.h"

TFT_eSPI tft = TFT_eSPI();
uint_fast64_t shutdown;

void setup() {
    // put your setup code here, to run once:
    tft.init();
    tft.setRotation(1);
    tft.setSwapBytes(true);
    tft.fillScreen(TFT_WHITE);
}

void loop() {
    for (int i = 0; i < frames; i++) {
        delay(40);
        tft.pushImage(60, 15, animation_width, animation_height, animation[i]);
    }
    if(shutdown++ > 16) espDeepSleep();
}