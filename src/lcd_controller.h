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
        void fillRect(int x_pos, int y_pos, int width, int height, uint8_t cell_val);
};

inline LCDState LCDController::getState()
{
    return state_;
}