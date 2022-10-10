#include "monty.h"

int _isdigit(char *str);

/**
 * _isdigit - checks for a digit from 0 to 9
 * @str: the integer to be checked
 *
 * Return: 1 if is digit, 0 otherwise
 */
int _isdigit(char *str)
{
	int i = 0;

	if (str == NULL)
		return (1);
	while (str[i])
	{
		if (isdigit(*str) == 0)
			return (1);
		i++;
	}
	return (0);
}

/**
 * push_op - push data into a stack
 * @stack: double pointer to first node
 * @line_number: line number
 */
void push_op(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *new_node;
	new_node = malloc(sizeof(stack_t));

	if (!new_node)
		get_error(2);

	if (_isdigit(data.args[1]) > 0)
		get_error(5);

	new_node->prev = NULL;
	new_node->n = atoi(data.args[1]);
	new_node->next = NULL;

	if (!*stack)
	{
		*stack = new_node;
		if (is_stack)
			bottom_s = *stack;
		else
			head_q = *stack;
	}
	else
	{
		if (is_stack)
		{
			new_node->next = *stack;
			(*stack)->prev = new_node;
		}
		else
		{
			new_node->prev = *stack;
			(*stack)->next = new_node;
		}
	}

	*stack = new_node;
	new_node = NULL;
	free(new_node);
}

/**
 * print_all_op - prints all elelment in the stack
 * @stack: double poitner ot first node
 * @line_number: line number
 */
void print_all_op(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!is_stack)
		temp = head_q;

	while (temp)
	{
		printf("%u\n", temp->n);
		temp = temp->next;
	}
}

/**
 * print_top_op - prints the top element of a stack
 * @stack: double pointer to the first node
 * @line_number: line number
 */
void print_top_op(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	if (is_stack)
	{
		if (!*stack)
			get_error(6);
		printf("%u\n", (*stack)->n);
	}
	else
	{
		if (!head_q)
			get_error(6);
		printf("%u\n", (head_q)->n);
	}
}

/**
 * pop_op - removes the top element of the stack
 * @stack: double pointer to first node
 * @line_number: line number
 */
void pop_op(stack_t **stack,
	       	__attribute__((unused)) unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!is_stack)
		temp = head_q;

	if (!temp)
		get_error(7);

	if (!(temp)->next)
	{
		free(temp);
		temp = NULL;
		if (!is_stack)
			head_q = temp;
	}
	else
	{
		temp = (temp)->next;
		free((temp)->prev);
		(temp)->prev = NULL;
		if (is_stack)
			*stack = temp;
		head_q = temp;
	}
}

/**
 * swap_top2_op - swaps the top two elements of the stack
 * @stack: ddouble pointer to the first node
 * @line_number: line number
 */
void swap_top2_op(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	int temp1;
	stack_t *temp2 = *stack;

	if (!is_stack)
		temp2 = head_q;

	if (!temp2 || !(temp2)->next)
		get_error(8);

	temp1 = (temp2)->n;
	(temp2)->n = (temp2)->next->n;
	(temp2)->next->n = temp1;
}

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

/**
 * mod_top2_op - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @stack: double pointer to the first node
 * @line_number: line number
 */
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
