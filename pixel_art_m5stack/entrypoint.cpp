/*
 * entrypoint.cpp
 * setup関数、loop関数の実装
 */
// #include "M5Stack.h"
#include "std_arduino.hpp"

LCDController *lcd;
PixelArtManager *mng;


void setup()
{
    const int kLCDHorizontalPixelNum = 320;
    const int kLCDVerticalPixelNum = 240;
    lcd = new LCDController(kLCDHorizontalPixelNum, kLCDVerticalPixelNum);
    mng = new PixelArtManager(lcd);
}


void loop()
{
    OperationType button = getButtonOperation();
    mng->drawNextFrame(button);
    mng->waitForNextFrame();
}
