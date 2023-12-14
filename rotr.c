#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: double pointer to the top of the stack
 * @line_number: line number where the opcode appears, unused
 *
 * Description: The last element of the stack becomes the top element.
 * This operation never fails.
 */
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *top, *bottom;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	top = *stack;

	while (top->next != NULL)
	{
		bottom = top;
		top = top->next;
	}

	bottom->next = NULL;
	top->prev = NULL;
	top->next = *stack;
	(*stack)->prev = top;
	*stack = top;
}
