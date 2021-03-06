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

struct PixelArtWithScale
{
    MonochromePixelArtWithFrame pixel_art;
    int scale;
};

class PixelArtManager
{
    private:
        LCDController *lcd_;
        std::vector<PixelArtWithScale> pixel_art_with_frame_list_;
        int current_art_no_;
        int draw_pos_x_;
        int draw_pos_y_;
    public:
        PixelArtManager(LCDController* lcd);
        void addPixelArtWithFrame(MonochromePixelArtWithFrame pixel_with_frame, int scale=1);
        void setDrawPosition(int pos_x, int pos_y);
        void drawPixelArt(MonochromePixelArt pixel_art, int pos_x, int pos_y, int scale);
        void drawNextFrame(OperationType operation);
        void waitForNextFrame();
};

#endif