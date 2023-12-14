#include "monty.h"

/**
 * mod - Computes remainder of division of the second top by the top element
 * @stack: Double pointer to the top of the stack
 * @line_number: The line number in the script
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;
}
