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

/*  getpath.c  */
list_dir *build_dir_list(void);
char *_getpath(char *command);

/*  bultins.c  */
int is_builtin(char *command);
void handle_builtin(char **command, char **argv, int *status, int idx,
char **new_env);
void exit_shell(char **command, char **argv, int *status, int idx,
char **new_env);
void print_env(char **command, char **argv, int *status, int idx,
char **new_env);

/* 08-builtins2.c */
void _setenv(char **command, char **argv, int *status, int idx,
char **new_env);
void _unsetenv(char **command, char **argv, int *status, int idx,
char **new_env);
void change_directory(char **command, char **argv, int *status, int idx,
char **new_env);

#endif
