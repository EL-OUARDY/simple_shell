#ifndef HEADER_GUARD
#define HEADER_GUARD

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/* shell buffer */
#define BUFFER_SIZE 1024
#define BUFFER_FLUSH -1

/* environement variable */
extern char **environ;

/**
 * struct shell_info_struct - hold all shell shared data
 *
 * @program_name: shell executable name
 * @prompt_number: count the user commands
 */
typedef struct shell_info_struct
{
	char *program_name;
	int prompt_number;
} shell_info_t;

/**
 * struct path_s - path struct
 *
 * @path: string path
 * @next: points to the next node
 */
typedef struct path_s
{
	char *path;
	struct path_s *next;
} path_t;

/* argument functions */
int argument_count(char *command);
char **split_command(char *command, int args_count);

/* command functions */
void process_command(char *user_command, shell_info_t *info);
void execute_child_process(char *user_command, char **args, int args_count);
char *validate_command(char *command);
int is_command_exists(const char *path);
char *command_fullpath(char *path, char *command);

/* list functions */
path_t *get_path_list();
path_t *add_path_node(path_t **head, const char *path);

/* environement functions */
char *_getenv(char *name);

/* error functions */
void command_not_found_error(char *command, shell_info_t *info);

/* string functions */
void print_shell_prompt(char *str);
void _print(const char *str, int fd);
int _putchar(char c, int fd);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(const char *str);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *int_to_string(int number);

/* cleanup functions */
void free_array(char **array, int length);
void free_path_list(path_t **head);

#endif
