#include "shell.h"

/**
 * execute_input - Execute the command
 * @tokens: the array of command
 * @av: command
 * Return : status
 */
int execute_input(char **tokens, char **av)
{
	char *full_command;
	
	pid_t child;
	int status;

	(void) av;
	full_command = _get_command(tokens[0]);
	if (!full_command)
	{
		perror("Error");
		free(tokens);
	}
	if (!tokens)
	{
		free(full_command);
		return (0):
	}
	child = fork();
	if (child == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	if (child == 0)
	{
		if (execve(full_command, tokens, environ) == -1)
		{
			free(full_command), full_command = NULL;
			free_buffer(tokens);
		}
		free(tokens), tokens = NULL;
	}
	else
	{
		wait(&status);
		free_buffer(tokens);
		free(full_command), full_command = NULL;
	}
	return (WEXITSTATUS(status));
}
