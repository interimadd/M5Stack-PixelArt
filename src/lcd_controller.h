#include <stdint.h>
#include <vector>


using LCDState = std::vector<std::vector<uint8_t>>;

class LCDController
{
    private:
        LCDState state_;
    public:
        LCDController(int horizontal_pixel_num, int vertical_pixel_num);
        LCDState getState();
};

inline LCDState LCDController::getState()
{
    return state_;
}