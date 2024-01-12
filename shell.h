#ifndef SHELL_H
#define SHELL_H

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/stat.h>

extern char **environ;

char *read_input(void);
char **_tokenize_input(char *input);
int execute_input(char **tokens, char **av);
char *_get_command(char *command);
void free_buffer(char **buffer);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_getenv(const char *var);

char *my_strdup(char *str);
int _strcmp(char *str1, char *str2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, const char *src);
int _strlen(const char *s);

#endif
