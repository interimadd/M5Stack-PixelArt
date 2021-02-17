#include <vector>
#include "lcd_controller.h"

using MonochromePixelArt = std::vector<std::vector<uint8_t>>;

class PixelArtManager
{
    private:
        LCDController *lcd_;
    public:
        PixelArtManager(LCDController* lcd);
        void drawPixelArt(MonochromePixelArt pixel_art, int pos_x, int pos_y, int scale);
};
