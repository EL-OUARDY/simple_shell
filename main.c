#include "shell.h"

/**
 * main - starting point
 * @ac: arguments count
 * @av: array of arguments
 * Return: integer
 */
int main(int ac __attribute__((unused)), char **av)
{
	pid_t child_pid;
	char *command, **args;
	size_t cmd_length;
	int read_bytes, args_count;

	while (1)
	{
		print_string("$ ");
		read_bytes = getline(&command, &cmd_length, stdin);

		/* handle the “end of file” condition */
		if (read_bytes == -1)
		{
			break; /* Exit the loop and the program */
		}

		/* remove the newline character */
		if (command[read_bytes - 1] == '\n')
		{
			command[read_bytes - 1] = '\0';
		}

		/* check if the command equal "exit" */
		if (_strcmp(command, "exit") == 0)
		{
			break; /* Exit the loop and the program */
		}

		/* get command args count */
		args_count = argument_count(command);

		/* split command into command/args array */
		args = split_command(command, args_count);

		child_pid = fork(); /* fork a child process */

		/* faild to create child process */
		if (child_pid == -1)
		{
			perror(av[0]);
			return (1);
		}

		if (child_pid == 0) /* child process */
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror(av[0]);
				return (1);
			}
		}
		else
		{ /* parent process */
			int status;

			waitpid(child_pid, &status, 0);
		}

		/* free arguments array */
		free_array(args, args_count);
	}

	/* free command variable */
	free(command);

	return (0);
}
