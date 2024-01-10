#include "shell.h"

/**
 *_tokenize_input - split the input into tokens
 * @input : user nput
 *Return: Always 0 (success)
 */
char **_tokenize_input(char *input)
{
	char * token;
	char *tmp = NULL;
	char **tokens = NULL;
	int j = 0, i = 0;

	if (!input)
		return (NULL);
	tmp = strdup(input);
	token = strtok(tmp, " ");
	if (token == NULL)
	{
		free(input), input = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		j++;
		token = strtok(NULL, " ");
	}
	free(tmp), tmp = NULL;
	tokens = malloc(sizeof(char*) * (j + 1));
	if (!tokens)
	{
		free(input), input = NULL;
		return (NULL);
	}
	tmp = strdup(input);
	token = strtok(tmp, " ");
	while (token)
	{
		tokens[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	free(input), input = NULL;
	tokens[i] = NULL;
	return (tokens);
}
