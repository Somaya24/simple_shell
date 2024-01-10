#include "shell.h"

char *_strdup(char* str)
{
	int len = strlen(str);
	char* str_dup=(char*)malloc(len*sizeof(char));

	str_dup = str;
	return (str_dup);
}
