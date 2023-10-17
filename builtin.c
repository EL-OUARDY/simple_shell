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
	int status_code;

	if (shell_info->args_count > 1) /* arguments are passed */
	{
		status_code = _atoi(shell_info->args[1]); /* convert to number */

		/* check if argument is a valid status code */
		if (is_numeric(shell_info->args[1]) && status_code >= 0)
		{
			/* free ressources */
			free(shell_info->user_command);
			free_array(shell_info->args, shell_info->args_count);

			exit(status_code); /* exit the program with user's status code */
		}
		else /* argument is NOT a valid status code */
		{
			/* Illegal number error message */
			exit_illegal_number_error(shell_info);

			/* free ressources */
			free_array(shell_info->args, shell_info->args_count);
		}
	}
	else /* no arguments are passed */
	{
		/* free ressources */
		free(shell_info->user_command);
		free_array(shell_info->args, shell_info->args_count);

		exit(0); /* exit the program with (0) status code */
	}
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

