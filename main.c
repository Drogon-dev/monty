#include "monty.h"

data_t data;
stack_t *head_q = NULL;
stack_t *bottom_s = NULL;
int is_stack = 1;

/**
 * main - program entry point
 * @argc: count of argv
 * @argv: pointer to pointers pf command line arguments
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	ssize_t line_read = 1;
	size_t len = 0;
	stack_t *stack = NULL;

	memset((void *) &data, 0, sizeof(data));
	if (argc != 2)
		get_error(1);

	data.filename = argv[1];
	data.fp = fopen(data.filename, "r");
	if (!data.fp)
		get_error(2);

	while ((line_read = getline(&data.line, &len, data.fp)) > 0)
	{
		if (*data.line == '\n')
			continue;

		data.line_number++;
		free(data.args);

		if (get_tokens() < 0)
			continue;
		if (*data.args == NULL)
			continue;
		get_op(&stack);
	}

	free_data();
	free_stack(stack);
	return (EXIT_SUCCESS);
}
