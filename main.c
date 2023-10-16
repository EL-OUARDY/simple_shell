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
	shell_info_t info; /* shell info */

	info.program_name = av[0]; /* save program name */
	info.prompt_number = 0;    /* initialize prompt counter */

	while (1)
	{
		print_shell_prompt("$ ");
		read_bytes = getline(&user_command, &cmd_length, stdin);

		/* handle the “end of file” condition */
		if (read_bytes == -1)
			break; /* exit the loop and the program */

		info.prompt_number++; /* increment prompt counter */

		/* remove the newline character */
		if (user_command[read_bytes - 1] == '\n')
			user_command[read_bytes - 1] = '\0';

		/* empty command */
		if (_strlen(user_command) == 0)
			continue; /* next iteration */

		/* execute command */
		process_command(user_command, &info);
	}

	free(user_command); /* free command variable */

	return (EXIT_SUCCESS);
}
