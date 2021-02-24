#ifndef PIXEL_ART_MANAGER_H
#define PIXEL_ART_MANAGER_H

#include "pixel_art.h"
#include "lcd_controller.h"

class PixelArtManager
{
    private:
        LCDController *lcd_;
    public:
        PixelArtManager(LCDController* lcd);
        void drawPixelArt(MonochromePixelArt pixel_art, int pos_x, int pos_y, int scale);
};

#endif