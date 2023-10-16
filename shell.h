#ifndef HEADER_GUARD
#define HEADER_GUARD

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* global environment variable */
extern char **environ;

/* argument functions */
int argument_count(char *command);
char **split_command(char *command, int args_count);

/* string functions */
void print_string(const char *str);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(const char *str);

/* cleanup functions */
void free_array(char **array, int length);

#endif
