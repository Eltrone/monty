#include "monty.h"
#include <string.h>
#include <stdio.h>

void execute_monty(FILE *file, stack_t **stack);
void free_stack(stack_t *stack);
instruction_t get_instruction(char *opcode);
void parse_line(char *line, stack_t **stack, unsigned int line_number);

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	FILE *monty_file;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	execute_monty(monty_file, &stack);

	fclose(monty_file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}

/**
 * execute_monty - Executes the Monty bytecodes from a file
 * @file: File pointer to the Monty bytecode file
 * @stack: Double pointer to the top of the stack
 */
void execute_monty(FILE *file, stack_t **stack)
{
	char buffer[1024];
	unsigned int line_number = 0;


	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		line_number++;
		parse_line(buffer, stack, line_number);
	}
}


/**
 * parse_line - Parses each line of the Monty bytecode file
 * @line: Line from the file
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the file
 */
void parse_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode;
	instruction_t instruction;

	opcode = strtok(line, "\n ");
	if (!opcode || opcode[0] == '#' || isspace((unsigned char)opcode[0]))
		return;

	instruction = get_instruction(opcode);
	if (instruction.f != NULL)
		instruction.f(stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * free_stack - Frees a stack
 * @stack: Pointer to the top of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

/**
 * get_instruction - Matches an opcode to its corresponding function
 * @opcode: The opcode to match
 * Return: An instruction_t containing the opcode and corresponding function
 */
instruction_t get_instruction(char *opcode)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pint", pint},
		{"pall", pall},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", monty_div},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL}
	};
	int i;
	instruction_t temp;


	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
			return (instructions[i]);
	}

	temp.opcode = NULL;
	temp.f = NULL;
	return (temp);
}
