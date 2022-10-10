#include "monty.h"

/**
 * stack_mode - sets the format of the data to a stack (LIFO)
 * @stack: double pointer to the first/last node depending on
 * mode
 * @line_number: line number
 */
void stack_mode(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	if (!is_stack)
	{
		bottom_s = *stack;
		*stack = head_q;
		is_stack = 1;
	}
}

/**
 * queue_mode - sets the format of the data to a queue (FIFO)
 * @stack: double pointer to the first/last node depending on
 * mode
 * @line_number: line number
 */
void queue_mode(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	if (is_stack)
	{
		head_q = *stack;
		*stack = bottom_s;
		is_stack = 0;
	}
}
