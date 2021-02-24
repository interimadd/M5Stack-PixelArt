#include "pixel_art.h"

MonochromePixelArtWithFrame::MonochromePixelArtWithFrame(std::vector<MonochromePixelArt> pixel_frame_lst){
    frame_pixel_arts_ = pixel_frame_lst;
    frame_length_ = pixel_frame_lst.size();
    current_frame_no_ = 0;
}

MonochromePixelArt MonochromePixelArtWithFrame::getCurrentFramePixelArt(){
    return frame_pixel_arts_[current_frame_no_];
}

MonochromePixelArt MonochromePixelArtWithFrame::toNextFrame(){
    if(++current_frame_no_ >= frame_length_) current_frame_no_ = 0;
    return frame_pixel_arts_[current_frame_no_];
}


PixelArtManager::PixelArtManager(LCDController* lcd)
{
    lcd_ = lcd;
}

void PixelArtManager::drawPixelArt(MonochromePixelArt pixel_art, int pos_x, int pos_y, int scale)
{
    int vertical_pixel_num = pixel_art.size();
    int horizontal_pixel_num = pixel_art[0].size();
    for(int hp=0; hp<horizontal_pixel_num; hp++){
        for(int vp=0; vp<vertical_pixel_num; vp++){
            uint8_t pix_val = pixel_art[vp][hp];
            lcd_->fillRect(pos_y+vp*scale, pos_x+hp*scale, scale, scale, pix_val);
        }
    }
}