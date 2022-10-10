#include "monty.h"

#define DELIMITER " \n\t\a"
/**
 * get_tokens - splits a line of text to tokens
 *
 * Return: postitive number on sucess, negative
 * if otherwise
 */
int get_tokens(void)
{
	char *token;
	size_t size = 4, new_size, count = 0;

	data.args = malloc(size * sizeof(char *));
	if (!data.args)
		get_error(2);

	token = strtok(data.line, DELIMITER);
	while (token)
	{
		data.args[count++] = token;
		if (count >= size)
		{
			new_size = size * 2;
			data.args = _realloc(data.args, size * sizeof(char *),
					new_size * sizeof(char *));
			if (data.args == NULL)
				get_error(2);
			size = new_size;
		}
		token = strtok(NULL, DELIMITER)
	}

	data.args[count] = NULL;
	if (**data.args == '#')
		return (-1);
	return (0);
}
#undef DELIMITER
