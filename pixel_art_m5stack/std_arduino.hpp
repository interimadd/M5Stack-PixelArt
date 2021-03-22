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

void setup();
void loop();

#endif //STD_ARDUINO_HPP