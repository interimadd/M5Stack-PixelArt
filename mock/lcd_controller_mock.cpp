#include "../src/lcd_controller.h"


LCDController::LCDController(int horizontal_pixel_num, int vertical_pixel_num)
{
    LCDState init_state(vertical_pixel_num, std::vector<uint8_t>(horizontal_pixel_num));
    state_ = init_state;
}
