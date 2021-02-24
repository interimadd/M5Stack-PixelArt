#ifndef PIXEL_ART_H
#define PIXEL_ART_H

#include <vector>
#include <stdint.h>

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

#endif