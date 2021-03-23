#include <iostream>
#include <iomanip>
#include <unistd.h>
#include "../pixel_art_m5stack/std_arduino.hpp"

const int RESIZE_GAIN = 15;


OperationType getButtonOperation()
{
    const int PIXEL_ART_CHANGE_FRAME_NUM = 4;
    static int loop_num = 0;
    if(++loop_num%PIXEL_ART_CHANGE_FRAME_NUM == 0){
        return OperationType::NEXT_BUTTON;
    }
    return OperationType::NO_OPERATION;
}


void printToConsole()
{
    LCDState state_ = lcd->getState();
    int height_ = state_.size();
    int width_ = state_[0].size();
    std::cout<<"\e[?25l";  // hide cursor
    system("clear");  // clear console
    for(int v_idx=0; v_idx<height_; v_idx+=RESIZE_GAIN){
        for(int h_idx=0; h_idx<width_; h_idx+=RESIZE_GAIN){
            if(state_[v_idx][h_idx] == 0) std::cout << "  ";
            else std::cout << "■ ";
        }
        std::cout<<"\n";
    }
    std::cout<<std::flush;
    std::cout<<"\e["<<height_<<"A";  // move cursor to top
}


int main()
{
    setup();
    while(1){
        loop();
        printToConsole();
        sleep(1);
    }
    return 0;
}