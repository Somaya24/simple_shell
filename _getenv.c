#include "shell.h"

/**
 * _getenv - Gets an environmental variable from the PATH.
 * @env_var: The name of the environmental variable to get.
 *
 * Return: If the environmental variable does not exist - NULL.
 *         Otherwise - a pointer to the environmental variable.
 */
char* _getenv(const char *env_var)
{
	int i, len;
	extern char **environ;

	len = _strlen(env_var);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(env_var, environ[i], len) == 0 && environ[i][len] == '=')
			return (&environ[i][len + 1]);
	}

	return (NULL);
}
