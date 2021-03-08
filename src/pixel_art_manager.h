#ifndef PIXEL_ART_MANAGER_H
#define PIXEL_ART_MANAGER_H

#include <vector>
#include "pixel_art.h"
#include "lcd_controller.h"

enum struct OperationType
{
    NO_OPERATION,
    NEXT_BUTTON,
};

class PixelArtManager
{
    private:
        LCDController *lcd_;
        std::vector<MonochromePixelArtWithFrame> pixel_art_with_frame_list_;
        int current_art_no_;
    public:
        PixelArtManager(LCDController* lcd);
        void addPixelArtWithFrame(MonochromePixelArtWithFrame pixel_with_frame);
        void drawPixelArt(MonochromePixelArt pixel_art, int pos_x, int pos_y, int scale);
        void drawNextFrame(OperationType operation);
};

#endif