#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number where the opcode appears
 *
 * Description: The function prints the ASCII character corresponding to
 * the integer at the top of the stack. If the stack is empty or the value
 * is not in the ASCII range, an error is printed and the program exits.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;
	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", value);
}
