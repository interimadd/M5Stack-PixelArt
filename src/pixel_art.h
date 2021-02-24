#include <vector>
#include "lcd_controller.h"

using MonochromePixelArt = std::vector<std::vector<uint8_t>>;

class MonochromePixelArtWithFrame{
    private:
        std::vector<MonochromePixelArt> frame_pixel_arts_;
        int frame_length_;
        int current_frame_no_;
    public:
        MonochromePixelArtWithFrame(std::vector<MonochromePixelArt>);
        MonochromePixelArt getCurrentFramePixelArt();
        MonochromePixelArt toNextFrame();
};

class PixelArtManager
{
    private:
        LCDController *lcd_;
    public:
        PixelArtManager(LCDController* lcd);
        void drawPixelArt(MonochromePixelArt pixel_art, int pos_x, int pos_y, int scale);
};
