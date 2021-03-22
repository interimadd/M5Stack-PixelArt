/*
 * std_arduino.hpp
 * ArduinoをC/C++で実装するに当たって必須のヘッダファイル
 */
#ifndef STD_ARDUINO_HPP
#define STD_ARDUINO_HPP

#include "../src/button_service.h"
#include "../src/pixel_art_manager.h"

extern int LCD_HORIZONTAL_PIXEL_NUM;
extern int LCD_VERTICAL_PIXEL_NUM;

extern LCDController *lcd;
extern PixelArtManager *mng;

extern std::vector<std::vector<MonochromePixelArt>> ALL_PIXEL_ARTS_LIST;
extern int PIXEL_ART_POS_X;
extern int PIXEL_ART_POS_Y;
extern int PIXEL_ART_SCALE;

void setup();
void loop();

#endif //STD_ARDUINO_HPP