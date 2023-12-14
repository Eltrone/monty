#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the top of the stack
 * @line_number: script line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	tab_s *new_node;
	char *arg;
	int num;

	/* Obtention de l'argument pour push */
	arg = strtok(NULL, " \n\t\r");
	if (arg == NULL || !is_number(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Conversion de l'argument en entier */
	num = atoi(arg);

	/* Création d'un nouveau nœud */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Initialisation du nouveau nœud */
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;

	/* Mise à jour de l'ancien sommet de la pile */
	if (*stack != NULL)
		(*stack)->prev = new_node;

	/* Mise à jour du sommet de la pile */
	*stack = new_node;
}

/**
 * is_number - checks if a string is a valid number
 * @str: string to check
 * Return: 1 if string is a number, 0 otherwise
 */
int is_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;

	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}

	return (1);
}
