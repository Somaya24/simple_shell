#include "shell.h"

/**
 *
 * main Entry point
 * @ac: Argument count
 * @av: argument vector
 * Return status code
 */

int main(int ac, char **av)
{
	char *input = NULL, **tokens = NULL;
	int status = 0;
	(void) ac;

	while(1)
	{
		input = read_input();
		if (input == NULL)/* EOF reached */
		{
			if (isatty(0))
				write(1, "\n", 1);
			free(input), input = NULL;
			return (status);
		}
		/*function tokenizer */
		tokens = _tokenize_input(input);
		if (!tokens)
			continue;

		status = execute_input(tokens, av);
		free_buffer(tokens);
	}
	return (0);
}
