#include "shell.h"

/**
 * my_strdup - Duplicate a string using dynamic memory allocation
 * @str: The input string to be duplicated
 * Return: A pointer to the newly allocated and duplicated string
 */
char *my_strdup(char *str)
{
	int len = strlen(str);
	char *str_dup = (char *)malloc((len + 1) * sizeof(char));

	if (!str_dup)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	_strcpy(str_dup, str);
	return (str_dup);
}
