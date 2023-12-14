#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the top of the stack
 * @line_number: script line number
 */
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node, *temp;
    char *arg;
    int num;

    arg = strtok(NULL, " \n\t\r");
    if (arg == NULL || !is_number(arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    num = atoi(arg);
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = num;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (monty_mode == MODE_STACK || *stack == NULL)
    {
        new_node->next = *stack;
        if (*stack != NULL)
            (*stack)->prev = new_node;
        *stack = new_node;
    }
    else
    {
        temp = *stack;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
    }
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
