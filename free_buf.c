#include "shell.h"

/**
* free_buffer - frees buffers
* @buffer: buffer to be freed
*
* Return: no return
*/
void free_buffer(char **buffer)
{
	int i = 0;

	if (!buffer || buffer == NULL)
		return;
	while (buffer[i])
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}
