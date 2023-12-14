#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: double pointer to the top of the stack
 * @line_number: line number where the opcode appears, unused
 *
 * Description: The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one.
 * This operation never fails.
 */
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *top, *bottom;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	top = *stack;
	bottom = *stack;

	while (bottom->next != NULL)
		bottom = bottom->next;

	*stack = top->next;
	(*stack)->prev = NULL;
	bottom->next = top;
	top->prev = bottom;
	top->next = NULL;
}
