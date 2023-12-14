#include "monty.h"

/**
 * pall - prints all the values on the stack
 * @stack: double pointer to the top of the stack
 * @line_number: script line number
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
