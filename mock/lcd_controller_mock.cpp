#include "../pixel_art_m5stack/src/lcd_controller.h"


LCDController::LCDController(int horizontal_pixel_num, int vertical_pixel_num)
{
    LCDState init_state(vertical_pixel_num, std::vector<uint8_t>(horizontal_pixel_num));
    state_ = init_state;
    height_ = vertical_pixel_num;
    width_ = horizontal_pixel_num;
}

void LCDController::fillRect(int v_pos, int h_pos, int v_len, int h_len, uint8_t cell_val)
{
    int v_pos_end = v_pos + v_len;
    int h_pos_end = h_pos + h_len;
    for(int v_idx=v_pos; v_idx<v_pos_end; v_idx++){
        for(int h_idx=h_pos; h_idx<h_pos_end; h_idx++){
            if(v_idx < 0 || v_idx >= height_) continue;
            if(h_idx < 0 || h_idx >= width_) continue;
            state_[v_idx][h_idx] = cell_val;
        }
    }
}

void LCDController::waitForNextFrame(){
    // wait is not required for test
}