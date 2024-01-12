#include "shell.h"

/**
 * _strcpy - copies the string pointed to by src to the 
 *           buffer pointed by dest
 * @dest: pointer to the destination of copied string
 * @src: pointer to the source string
 * return: pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
