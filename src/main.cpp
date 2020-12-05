
#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include <sleep.hpp>
#include "animation.h"

TFT_eSPI tft = TFT_eSPI();
uint_fast64_t shutdown;

void setup() {
    tft.init();
    tft.setRotation(1);
    tft.setSwapBytes(true);
    tft.fillScreen(TFT_BLACK);
}

void loop() {
    if(shutdown++ > 5) espDeepSleep();
    for (int i = 0; i < frames; i++) {
        tft.pushImage(2, 0, animation_width, animation_height, animation[i]);
        delay(120);
    }
}