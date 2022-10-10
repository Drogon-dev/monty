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
