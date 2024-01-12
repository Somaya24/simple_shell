#include "shell.h"

/**
 * _get_command - search for the full path of a command 
 *                in directories specified by PATH
 * @command: The command for which to find the full path
 *
 * Return: the full path of the command if found, NULL otherwise
 */
char *_get_command(char *command)
{
	char *path;
	char *dir, *full_command;
	struct stat st;

	path = _getenv("PATH");
	if (!path)
		return (NULL);

	dir = strtok(path, ":");
	while (dir)
	{
		full_command = malloc(_strlen(dir) + _strlen(command) + 2);
		if (full_command == NULL)
		{
			perror("malloc failed");
			exit(EXIT_FAILURE);
		}
		_strcpy(full_command, dir);
		_strcat(full_command, "/");
		_strcat(full_command, command);

		if (stat(full_command, &st) == 0)
		{
			free(path);
			return (full_command);
		}
		free(full_command), full_command = NULL;
		dir = strtok(NULL, ":");
	}
	free(path) ;
	return (NULL);
}
