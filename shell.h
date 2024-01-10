#ifndef SHELL_H
#define SHELL_H

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern char **environ;

char *read_input(void);
char **_tokenize_input(char *input);
int execute_input(char **tokens, char **av);


char *_strdup(char* str);

#endif
