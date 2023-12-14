#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number of the Monty bytecodes file.
 */
void add(stack_t **stack, unsigned int line_number)
{
    int sum;

    /* Check if the stack contains at least two elements */
    if (!(*stack) || !((*stack)->next))
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Add the top two elements */
    sum = (*stack)->n + (*stack)->next->n;

    /* Pop the top element */
    pop(stack, line_number);

    /* Update the new top element with the sum */
    (*stack)->n = sum;
}
