#include "monty.h"

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @info: pointer to the info structure (contains mode and top of stack)
 * @line_number: script line number (unused)
 *
 * Description: This function sets the mode of operation to STACK,
 * indicating that the data structure should behave as a stack
 * (Last In, First Out).
 */
void stack(info_t *info, unsigned int line_number __attribute__((unused)))
{
	info->mode = STACK;
}
