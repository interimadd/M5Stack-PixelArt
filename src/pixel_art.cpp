#include "pixel_art.h"


PixelArtManager::PixelArtManager(LCDController* lcd)
{
    lcd_ = lcd;
}

void PixelArtManager::drawPixelArt(MonochromePixelArt pixel_art, int pos_x, int pos_y, int scale)
{
    int vertical_pixel_num = pixel_art.size();
    int horizontal_pixel_num = pixel_art[0].size();
    for(int hp=pos_y; hp<pos_y+vertical_pixel_num; hp++){
        for(int vp=pos_x; vp<pos_x+horizontal_pixel_num; vp++){
            uint8_t pix_val = pixel_art[hp][vp];
            lcd_->fillRect(hp, vp, 1, 1, pix_val);
        }
    }
}