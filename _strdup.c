#include "shell.h"

char *my_strdup(char* str)
{
	int len = strlen(str);
	char* str_dup=(char*)malloc(len*sizeof(char));

	if (!str_dup)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	_strcpy(str_dup, str);
	return (str_dup);
}
