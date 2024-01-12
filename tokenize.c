#include "shell.h"

/**
 *_tokenize_input - split the input into tokens
 * @input : user input
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
	tmp = my_strdup(input);
	token = strtok(tmp, " ");
	if (token == NULL)
	{
		free_buffer(input);
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
		free_buffer(input);
		return (NULL);
	}
	tmp = my_strdup(input);
	token = strtok(tmp, " ");
	while (token)
	{
		tokens[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	free_buffer(input);
	tokens[i] = NULL;
	return (tokens);
}
