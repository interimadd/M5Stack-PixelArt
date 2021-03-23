#include "src/button_service.h"
#include <M5Stack.h>


OperationType getButtonOperation()
{
    M5.update();// update button state
    if (M5.BtnC.wasPressed()) return OperationType::NEXT_BUTTON;
    return OperationType::NO_OPERATION;
}
