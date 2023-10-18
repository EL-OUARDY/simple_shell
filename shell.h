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
 * struct builtin_s - builtin command struct
 *
 * @command: builtin command (ex: exit / cd / help / alias ...etc)
 * @handler_func: The associated handler function
 */
typedef struct builtin_s
{
	char *command;
	void (*handler_func)();
} builtin_t;

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

/**
 * struct env_s - environement struct
 *
 * @variable: string - env variable
 * @next: points to the next node
 */
typedef struct env_s
{
	char *variable;
	struct env_s *next;
} env_t;

/**
 * struct shell_info_struct - hold all shell shared data
 *
 * @program_name: shell executable name
 * @prompt_number: count the user commands
 * @user_command: string user command
 * @args: arguments array
 * @args_count: argument array's length
 * @env: environement list
 */
typedef struct shell_info_struct
{
	char *program_name;
	int prompt_number;
	char *user_command;
	char **args;
	int args_count;
	env_t *env;
} shell_info_t;

/* argument functions */
int argument_count(char *command);
char **split_command(shell_info_t *shell_info);

/* command functions */
void process_command(shell_info_t *shell_info);
void execute_child_process(shell_info_t *shell_info);
char *validate_command(shell_info_t *shell_info);
int is_command_exists(const char *path);
char *command_fullpath(char *path, char *command);

/* builtin function */
int call_builtin_handler_func(shell_info_t *shell_info);
void handle_exit(shell_info_t *shell_info);
void handle_env(shell_info_t *shell_info);
void handle_setenv(shell_info_t *shell_info);
void handle_unsetenv(shell_info_t *shell_info);

/* list functions */
path_t *get_path_list(shell_info_t *shell_info);
path_t *add_path_node(path_t **head, const char *path);
env_t *add_env_node(env_t **head, const char *variable);
char **env_list_to_array(env_t *head);

/* environement functions */
void populate_shell_env(shell_info_t *shell_info);
char *_getenv(char *name, shell_info_t *shell_info);
void _setenv(char *name, char *value, shell_info_t *shell_info);
int _unsetenv(char *name, shell_info_t *shell_info);

/* error functions */
void command_not_found_error(shell_info_t *shell_info);
void exit_illegal_number_error(shell_info_t *shell_info);
void custom_error_message(char *message, shell_info_t *shell_info);

/* cleanup functions */
void free_all_ressources(shell_info_t *shell_info);
void free_array(char **array);
void free_path_list(path_t **head);
void free_env_list(env_t **head);

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
int is_numeric(const char *str);
int _atoi(const char *str);

/* shell info struct intializer */
#define SHELL_INFO_INIT          \
{                              \
	NULL, 0, NULL, NULL, 0, NULL \
}

#endif
