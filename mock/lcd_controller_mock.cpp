#include "../src/lcd_controller.h"


LCDController::LCDController(int horizontal_pixel_num, int vertical_pixel_num)
{
    LCDState init_state(vertical_pixel_num, std::vector<uint8_t>(horizontal_pixel_num));
    state_ = init_state;
    height_ = vertical_pixel_num;
    width_ = horizontal_pixel_num;
}

void LCDController::fillRect(int x_pos, int y_pos, int width, int height, uint8_t cell_val)
{
    for(int h_idx=y_pos; h_idx<width && h_idx<height_; h_idx++){
        for(int v_idx=x_pos; v_idx<width && v_idx<width_; v_idx++){
            state_[h_idx][v_idx] = cell_val;
        }
    }
}