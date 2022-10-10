#include "monty.h"

/**
 * add_top2_op - adds the top two elements of the stack
 * @stack: double pointer to the first node
 * @line_number: line number
 */
void add_top2_op(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *temp2 = *stack;

	if (!is_stack)
		temp2 = head_q;

	if (!temp2 || !(temp2)->next)
		get_error(9);
	
	(temp2)->next->n += (temp2)->n;
	pop_op(stack, data.line_number);
}

/**
 * nop_op - doesn’t do anything.
 * @stack: double pointer to first node
 * @line_number: line number
 */
void nop_op(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{}

/**
 * sub_top2_op - subtracts the top element of the stack 
 * from the second top element of the stack.
 * @stack: double pointer to the first node
 * @line_number: line number
 */
void sub_top2_op(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp2 = *stack;

	if (!is_stack)
		temp2 = head_q;

	if (!temp2 || !(temp2)->next)
		get_error(10);

	(temp2)->next->n -= (temp2)->n;
	pop_op(stack, data.line_number);
}

/**
 * div_top2_op -  divides the second top element of the
 * stack by the top element of the stack
 * @stack: double pointer to the first node
 * @line_number: line number
 */
void div_top2_op(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *temp2 = *stack;

	if (!is_stack)
		temp2 = head_q;

	if (!temp2 || !(temp2)->next)
		get_error(11);

	if (temp2->n == 0)
		get_error(12);

	(temp2)->next->n /= (temp2)->n;
	pop_op(stack, data.line_number);
}

/**
 * mul_top2_op - multiplies the second top element of the
 * stack with the top element of the stack.
 * @stack: double pointer to the first node
 * @line_number: line number
 */
void mul_top2_op(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *temp2 = *stack;

	if (!is_stack)
		temp2 = head_q;

	if (!temp2 || !(temp2)->next)
		get_error(13);

	(temp2)->next->n *= (temp2)->n;
	pop_op(stack, data.line_number);
}
