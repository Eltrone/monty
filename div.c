#include "monty.h"

/**
 * monty_div - Divides the second top element of the stack by the top element.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecodes file.
 *
 * Description: If the stack contains fewer than two elements or
 * the top element of the stack is 0, the function prints an error message
 * and exits with the status EXIT_FAILURE.
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	int result;

	/* Vérifier si la pile contient au moins deux éléments */
	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Vérifier la division par zéro */
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Effectuer la division */
	result = (*stack)->next->n / (*stack)->n;

	/* Pop le sommet de la pile */
	pop(stack, line_number);

	/* Mettre à jour le nouveau sommet avec le résultat */
	(*stack)->n = result;
}
