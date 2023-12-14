#include "monty.h"

global_t global_info = { MODE_STACK, NULL };

void stack(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    global_info.mode = MODE_STACK;
}
