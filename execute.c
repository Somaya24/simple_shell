#include "shell.h"

/**
 * execute_input - Execute the command
 * @tokens: the array of command
 * @av: command
 * Return : status
 */
int execute_input(char **tokens, char **av)
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	if (child == 0)
	{
		if (execve(tokens[0], tokens, environ) == -1)
		{
			perror(av[0]);
			free(tokens);
			exit(EXIT_FAILURE);
		}
		free(tokens), tokens = NULL;
	}
	else
	{
		wait(&status);
		free(tokens), tokens = NULL;
	}
	return (WEXITSTATUS(status));
}
