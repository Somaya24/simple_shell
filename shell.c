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
	int i, status = 0;

	while(1)
	{
		input = read_input();
		if (input == NULL)/* EOF reached */
		{
			if (isatty(0))
				write(1, "\n", 1);
			return (status);
			free(input);
		}
		/*function tokenizer */
		tokens = _tokenize_input(input);
		if (tokens == NULL)
			continue;
		/*for (i = 0; tokens[i]; i++)
			printf("%s\n", tokens[i]);
		
		free(tokens[i]), tokens[i] = NULL;
		free(tokens);*/
		
		status = execute_input(tokens, av);
	}
	free(input);
	return (0);
}
