#include "shell.h"

/**
 * remove_comment - clean command from comments
 * @command: string command
 * Return: void
 */
void remove_comment(char *command)
{
	int i = 0;

	/* place NULL termination at (#) sign */
	for (i = 0; command[i] != '\0'; i++)
	{
		if (command[i] == '#')
		{
			command[i] = '\0';
			break;
		}
	}
}
