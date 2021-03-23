#include "src/lcd_controller.h"
#include <M5Stack.h>


LCDController::LCDController(int horizontal_pixel_num, int vertical_pixel_num)
{
    M5.begin();
    M5.Power.begin();
    M5.Lcd.setBrightness(200);
    M5.Lcd.fillScreen(WHITE);
}

void LCDController::fillRect(int v_pos, int h_pos, int v_len, int h_len, uint8_t cell_val)
{
    uint16_t color = WHITE;
    if(cell_val > 0) color = BLACK;
    M5.Lcd.fillRect(h_pos, v_pos, h_len, v_len, color);
}

void LCDController::waitForNextFrame(){
    delay(1000);
}
