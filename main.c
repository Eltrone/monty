#include "monty.h"
#include <string.h>
#include <stdio.h>

void execute_monty(FILE *file, stack_t **stack);
void free_stack(stack_t *stack);
instruction_t get_instruction(char *opcode);
void parse_line(char *line, stack_t **stack, unsigned int line_number);

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
    return EXIT_SUCCESS;
}

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

void parse_line(char *line, stack_t **stack, unsigned int line_number)
{
    char *opcode;
    instruction_t instruction;

    opcode = strtok(line, "\n ");
    if (!opcode || opcode[0] == '#')
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

instruction_t get_instruction(char *opcode)
{
    instruction_t instructions[] = {
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {NULL, NULL}
    };
    int i;
    instruction_t temp;

    for (i = 0; instructions[i].opcode; i++)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
            return instructions[i];
    }

    temp.opcode = NULL;
    temp.f = NULL;
    return temp;
}
