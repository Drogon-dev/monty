#include "monty.h"

/**
 * get_op - process and parse line
 * and get perform the required operation
 * @stack: the stack
 *
 * Return: integer
 */
int get_op(stack_t **stack)
{
	instruction_t inst[] = {
		{"push", push_op},
		{"pall", print_all_op},
		{"pint", print_top_op},
		{"pop", pop_op},
		{"swap", swap_top2_op},
		{"nop", nop_op},
		{"add", add_top2_op},
		{"sub", sub_top2_op},
		{"div", div_top2_op},
		{"mul", mul_top2_op},
		{"mod", mod_top2_op},
		{"pchar", pchar_op},
		{"pstr", pstr_op},
		{"rotl", rotl_op},
		{"rotr", rotr_op},
		{"stack", stack_mode},
		{"queue", queue_mode},
		{NULL, NULL}
	};
	int i = 0;

	while ((inst + i)->opcode)
	{
		if (strcmp((inst + i)->opcode, *data.args) == 0)
		{
			(inst + i)->f(stack, data.line_number);
			return (0);
		}
		i++;
	}

	get_error(3);
	return (1);
}
