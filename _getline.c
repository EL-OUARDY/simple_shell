#include "shell.h"

/**
 * _getline -  a function that prints a prompt
 * and get input from stdin.
 * Return: the input string in success
 * otherwise return NULL.
 */
char *_getline(void)
{
	char *line = NULL;
	size_t len = 0;

	/* Print "$ " if stdout is a terminal (interactive mode) */
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, PROMPT, 2);

	/* Get input from stdin */
	if (getline(&line, &len, stdin) == -1)
	{
		/* If getline failed "EOF condition" (the user type Ctrl+D) */
		free(line);
		return (NULL);
	}

	/* Return the line contains the input */
	return (line);
}
