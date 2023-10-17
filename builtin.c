#include "shell.h"

/**
 * call_builtin_handler_func - call the right builtin function to execute
 * @shell_info: shell information
 * Return: (1) success (0) not found
 */
int call_builtin_handler_func(shell_info_t *shell_info)
{
	int index, array_size;

	builtin_t builtins[] = {
		{"exit", handle_exit},
		{"env", handle_env},
		/* add builtins here */
	};

	/* get builtins array size */
	array_size = sizeof(builtins) / sizeof(builtins[0]);

	/* loop over builtins array to find a match */
	for (index = 0; index < array_size; index++)
	{
		if (strcmp(builtins[index].command, shell_info->args[0]) == 0)
		{
			/* call the handler */
			builtins[index].handler_func(shell_info);
			return (1);
		}
	}

	/* returning 0 indicates no match found*/
	return (0);
}

/**
 * handle_exit - handle builtin exit command
 * @shell_info: shell information
 * Return: void
 */
void handle_exit(shell_info_t *shell_info)
{
	/* free ressources */
	free(shell_info->user_command);
	free_array(shell_info->args, shell_info->args_count);

	exit(0);                      /* exit the program */
}

/**
 * handle_env - handle builtin env command
 * @shell_info: shell information
 * Return: void
 */
void handle_env(shell_info_t *shell_info)
{
	int i = 0;

	/* Loop through the environment variables */
	while (environ[i])
	{
		/* Print the environment variable */
		_print(environ[i], STDOUT_FILENO);
		_putchar('\n', STDOUT_FILENO); /* new line */
		_putchar(BUFFER_FLUSH, STDOUT_FILENO); /* flush buffer */

		i++;
	}

	/* free ressources */
	free_array(shell_info->args, shell_info->args_count);
}
