#include "shell.h"

/**
 * call_builtin_handler_func - call the right builtin function to execute
 * @user_command: command to execute
 * @args: arguments to the command
 * @args_count: number of arguments
 * @info: shell information
 * Return: (1) success (0) not found
 */
int call_builtin_handler_func(
		char *user_command,
		char **args,
		int args_count,
		shell_info_t *info)
{
	int index, array_size;

	builtin_t builtins[] = {
		{"exit", handle_exit},
		/* add builtins here */
	};

	/* get builtins array size */
	array_size = sizeof(builtins) / sizeof(builtins[0]);

	/* loop over builtins array to find a match */
	for (index = 0; index < array_size; index++)
	{
		if (strcmp(builtins[index].command, args[0]) == 0)
		{
			/* call the handler */
			builtins[index].handler_func(user_command, args, args_count, info);
			return (1);
		}
	}

	/* returning 0 indicates no match found*/
	return (0);
}

/**
 * handle_exit - handle builtin exit command
 * @user_command: command to execute
 * @args: arguments to the command
 * @args_count: number of arguments
 * @info: shell information
 * Return: void
 */
void handle_exit(
		char *user_command,
		char **args,
		int args_count,
		shell_info_t *info)
{
	(void)info;
	free(user_command);           /* free command variable */
	free_array(args, args_count); /* free arguments array */
	exit(0);                      /* exit the program */
}
