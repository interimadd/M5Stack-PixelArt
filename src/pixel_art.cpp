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
