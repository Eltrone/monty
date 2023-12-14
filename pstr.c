#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number where the opcode appears
 *
 * Description: Prints characters represented
 * by the integer values in the stack
 * until the stack is over, the value is 0,
 * or the value is not in the ASCII range.
 */
void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current != NULL && current->n > 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
