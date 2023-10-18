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
		{"setenv", handle_setenv},
		{"unsetenv", handle_unsetenv},
		/* builtins added here */
	};

	/* get builtins array size */
	array_size = sizeof(builtins) / sizeof(builtins[0]);

	/* loop over builtins array to find a match */
	for (index = 0; index < array_size; index++)
	{
		if (_strcmp(builtins[index].command, shell_info->args[0]) == 0)
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
			/* free memory */
			free_all_ressources(shell_info);

			exit(status_code); /* exit the program with user's status code */
		}
		else /* argument is NOT a valid status code */
		{
			/* Illegal number error message */
			exit_illegal_number_error(shell_info);

			/* free arguments array */
			free_array(shell_info->args);
		}
	}
	else /* no arguments are passed */
	{
		/* free memory */
		free_all_ressources(shell_info);

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
	env_t *head;

	/* Loop through the environment variables */
	head = shell_info->env;
	while (head != NULL)
	{
		/* Print the environment variable */
		_print(head->variable, STDOUT_FILENO);
		_putchar('\n', STDOUT_FILENO);		   /* new line */
		_putchar(BUFFER_FLUSH, STDOUT_FILENO); /* flush buffer */

		head = head->next;
	}

	/* free arguments array */
	free_array(shell_info->args);
}

/**
 * handle_setenv - handle builtin setenv command
 * @shell_info: shell information
 * Description: FORMAT: setenv {variable_name} {variable_value}
 * Return: void
 */
void handle_setenv(shell_info_t *shell_info)
{
	if (shell_info->args_count != 3)
	{
		custom_error_message("invalid number of arguments\n", shell_info);
	}
	else
	{
		/* set or update env variable */
		_setenv(shell_info->args[1], shell_info->args[2], shell_info);
	}

	/* free arguments array */
	free_array(shell_info->args);
}

/**
 * handle_unsetenv - handle builtin unsetenv command
 * @shell_info: shell information
 * Description: FORMAT: unsetenv {variable_name}
 * Return: void
 */
void handle_unsetenv(shell_info_t *shell_info)
{
	if (shell_info->args_count != 2)
	{
		custom_error_message("invalid number of arguments\n", shell_info);
	}
	/* remove env variable */
	else if (_unsetenv(shell_info->args[1], shell_info) == -1)
	{
		custom_error_message("environement variable not found\n", shell_info);
	}

	/* free arguments array */
	free_array(shell_info->args);
}
