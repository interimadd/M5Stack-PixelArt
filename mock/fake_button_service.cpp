#include "../src/button_service.h"
#include "fake_button_service.h"

static OperationType current_op = OperationType::NO_OPERATION;

OperationType getButtonOperation()
{
    return current_op;
}

void setButtonoperation(OperationType op)
{
    current_op = op;
}