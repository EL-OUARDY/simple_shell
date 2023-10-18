#include "shell.h"

/**
 * main - starting point
 * @ac: argument count
 * @av: argument vector
 * Return: integer
 */
int main(int ac __attribute__((unused)), char **av)
{
	size_t cmd_length;
	int read_bytes;
	char *user_command = NULL;
	shell_info_t shell_info = SHELL_INFO_INIT; /* initialize shell info */

	shell_info.program_name = av[0]; /* save program name */
	shell_info.prompt_number = 0;	 /* initialize prompt counter */
	populate_shell_env(&shell_info); /* initialize shell env */

	while (1)
	{
		if (isatty(STDIN_FILENO)) /* interactive mode */
			print_shell_prompt("$ ");
		read_bytes = _getline(&user_command, &cmd_length, 0);

		/* handle the “end of file” condition */
		if (read_bytes == -1)
			break; /* exit the loop and the program */

		shell_info.prompt_number++; /* increment prompt counter */

		/* remove the newline character */
		if (user_command[read_bytes - 1] == '\n')
			user_command[read_bytes - 1] = '\0';

		/* empty command */
		if (_strlen(user_command) == 0)
			continue; /* next iteration */

		/* execute command */
		shell_info.user_command = user_command;
		process_command(&shell_info);
	}

	free(user_command);				/* free command variable */
	free_env_list(&shell_info.env); /* free env list */

	return (EXIT_SUCCESS);
}

