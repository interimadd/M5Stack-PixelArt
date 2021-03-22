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
    lcd = new LCDController(LCD_HORIZONTAL_PIXEL_NUM, LCD_VERTICAL_PIXEL_NUM);
    mng = new PixelArtManager(lcd);
}


void loop()
{
    OperationType button = getButtonOperation();
    mng->drawNextFrame(button);
    mng->waitForNextFrame();
}
