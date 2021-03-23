#include "pixel_art_manager.h"

PixelArtManager::PixelArtManager(LCDController* lcd)
{
    lcd_ = lcd;
    current_art_no_ = 0;
    draw_pos_x_ = 0;
    draw_pos_y_ = 0;
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

void PixelArtManager::addPixelArtWithFrame(MonochromePixelArtWithFrame pixel_with_frame, int scale)
{
    PixelArtWithScale info = {pixel_with_frame, scale};
    pixel_art_with_frame_list_.push_back(info);
}


void PixelArtManager::drawNextFrame(OperationType operation)
{

    if(pixel_art_with_frame_list_.size() == 0) return;
    if(operation == OperationType::NEXT_BUTTON) current_art_no_++;
    if(current_art_no_ >= pixel_art_with_frame_list_.size()) current_art_no_ = 0;
    MonochromePixelArt pixel_art_to_display = pixel_art_with_frame_list_[current_art_no_].pixel_art.toNextFrame();
    drawPixelArt(pixel_art_to_display, draw_pos_x_, draw_pos_y_,
                 pixel_art_with_frame_list_[current_art_no_].scale);
}


void PixelArtManager::setDrawPosition(int pos_x, int pos_y)
{
    draw_pos_x_ = pos_x;
    draw_pos_y_ = pos_y;
}


void PixelArtManager::waitForNextFrame(){
    lcd_->waitForNextFrame();
}