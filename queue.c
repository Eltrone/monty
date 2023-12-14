#include "monty.h"

/**
 * op_queue - sets the data format to a queue (FIFO)
 * @stack: double pointer to the top of the stack
 * @line_number: line number in the script
 */
void op_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	monty_mode = MODE_QUEUE;
}
