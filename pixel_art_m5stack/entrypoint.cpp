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
    for(int idx=0; idx<ALL_PIXEL_ARTS_LIST.size(); idx++){
        MonochromePixelArtWithFrame *pixel_with_frame = new MonochromePixelArtWithFrame(ALL_PIXEL_ARTS_LIST[idx]);
        mng->addPixelArtWithFrame(*pixel_with_frame, PIXEL_ART_SCALE);
    }
    mng->setDrawPosition(PIXEL_ART_POS_X, PIXEL_ART_POS_Y);
}


void loop()
{
    OperationType button = getButtonOperation();
    mng->drawNextFrame(button);
    mng->waitForNextFrame();
}
