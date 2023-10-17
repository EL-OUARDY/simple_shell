#include "shell.h"

/**
 * argument_count - count command's arguments
 * @command: command with arguments
 *
 * Return: the counter of the arguments including command itself
 */
int argument_count(char *command)
{
	int count = 0;
	char *cmd, *token;

	/* copy command */
	cmd = _strdup(command);

	token = strtok(cmd, " ");
	while (token)
	{
		count++;
		token = strtok(NULL, " "); /* Continue splitting */
	}

	/* free copied command */
	free(cmd);

	return (count);
}

/**
 * split_command - command string to array
 * @shell_info: shell information
 * Return: an array contains the arguments of a command
 * including the command itself
 */
char **split_command(shell_info_t *shell_info)
{
	char **args;
	char *cmd, *token;
	int i = 0;

	/* copy command */
	cmd = _strdup(shell_info->user_command);

	/* allocate memory for command args */
	args = malloc(sizeof(char *) * (shell_info->args_count + 1));

	token = strtok(cmd, " ");
	while (token)
	{
		args[i] = _strdup(token);
		token = strtok(NULL, " "); /* Continue splitting */
		i++;
	}
	args[i] = NULL; /* Null-terminate the argument array */

	/* free copied command */
	free(cmd);

	return (args);
}
