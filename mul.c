#include "monty.h"

/**
 * mul - Multiplies the second top element with the top element of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: The line number in the script
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;
}
