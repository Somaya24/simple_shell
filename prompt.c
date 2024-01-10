#include "shell.h"

char *read_input(void)
{
	char *buffer = NULL;
	size_t s_buffer = 0;
	ssize_t num_input;

	if (isatty(0))
		write(1, "$ ", 2);

	num_input = getline(&buffer, &s_buffer, stdin);
	if (num_input == -1)
	{
		free(buffer), buffer = NULL;
		return(NULL);
	}
	return (buffer);
}
