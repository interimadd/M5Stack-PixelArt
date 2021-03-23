#ifndef LED_CONTROLLER_H
#define LED_CONTROLLER_H

#include <stdint.h>
#include <vector>


using LCDState = std::vector<std::vector<uint8_t>>;

class LCDController
{
    private:
        LCDState state_;
        int width_;
        int height_;
    public:
        LCDController(int horizontal_pixel_num, int vertical_pixel_num);
        LCDState getState();
        void fillRect(int v_pos, int h_pos, int v_len, int h_len, uint8_t cell_val);
        void waitForNextFrame();
};

inline LCDState LCDController::getState()
{
    return state_;
}

#endif