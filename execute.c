#include "shell.h"

/**
 *
 *
 *
 *
 */
int execute_input(char **tokens, char **av)
{
	pid_t child;
	int status, i;

	child = fork();
	if (child == 0)
	{
		if (execve(tokens[0], tokens, environ) == -1)
		{
			perror(av[0]);
			free(tokens);
		}
	}
	else
		wait(&status);
	i = 0;
	return (WEXITSTATUS(status));
}
