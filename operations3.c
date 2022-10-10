#include "monty.h"

void mod_top2_op(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *temp2 = *stack;

	if (!is_stack)
		temp2 = head_q;

	if (!temp2 || !(temp2)->next)
		get_error(14);

	if ((*stack)->n == 0)
		get_error(15);

	(temp2)->next->n %= (temp2)->n;
	pop_op(stack, data.line_number);
}

/**
 * pchar_op - prints the char at the top of the stack
 * followed by a new line.
 * @stack: double pointer to the first node
 * @line_number: line number
 */
void pchar_op(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!is_stack)
		temp = head_q;

	if (!temp)
		get_error(15);

	if (temp->n < 0 || temp->n > 127)
		get_error(16);

	putchar(temp->n);
	putchar('\n');
}

/**
 * pstr_op -  prints the string starting at the top of the
 * stack, followed by a new line.
 * @stack: double pointer to the first node
 * @line_number: line number
 */
void pstr_op(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!is_stack)
		temp = head_q;

	if (!temp)
		putchar('\n');

	while (temp)
	{
		if (temp->n > 127 || temp->n < 0)
			break;
		if (temp->n == 0)
			break;

		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}

/**
 * rotl_op - rotates the stack to the top
 * @stack: double pointer to the first node
 * @line_number: line number;
 */
void rotl_op(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *temp = *stack;
	int temp_val;

	if (!is_stack)
		temp = head_q;

	if (temp)
	{
		temp_val = (temp)->n;
		while (temp->next)
		{
			temp->n = temp->next->n;
			temp = temp->next;
		}
		temp->n = temp_val;
	}
}

/**
 * rotr_op - rotates the stack to the bottom
 * @stack: double pointer to the first node
 * @line_number: line number;
 */
void rotr_op(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *temp = *stack, *temp2 = *stack;
	int current_val, next_val;

	if (!is_stack)
	{
		temp = head_q;
		temp2 = head_q;
	}

	if (temp)
	{
		next_val = (temp)->n;
		while (temp->next)
		{
			current_val = next_val;
			next_val = temp->next->n;
			temp->next->n = current_val;
			temp = temp->next;
		}
		(temp2)->n = next_val;
	}
}
