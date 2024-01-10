#include "shell.h"

/**
 *
 * main - simple shell
 *
 * Return 0 (success)
 */

int main(int ac, char **av)
{
	char *input = NULL, **tokens = NULL;
	int status = 0, i;
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
		if (tokens == NULL)
			continue;
		for (i = 0; tokens[i]; i++)
		{
			free(tokens[i]);
			tokens[i] = NULL;
		}
		free(tokens);
		
		status = execute_input(tokens, av);
	}
	free(input), input = NULL;
	return (0);
}
