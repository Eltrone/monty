#include "monty.h"

/**
 * div - Divise le 2ème élément en haut de la pile par le sommet de la pile
 * @stack: double pointeur vers le sommet de la pile
 * @line_number: numéro de la ligne dans le script
 */
void div(stack_t **stack, unsigned int line_number)
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
