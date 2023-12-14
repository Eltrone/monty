#include "monty.h"

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @info: pointer to the info structure (contains mode and top of stack)
 * @line_number: script line number (unused)
 *
 * Description: This function sets the mode of operation to QUEUE,
 * indicating that the data structure should behave as a queue
 * (First In, First Out).
 */
void queue(info_t *info, unsigned int line_number __attribute__((unused)))
{
	info->mode = QUEUE;
}
