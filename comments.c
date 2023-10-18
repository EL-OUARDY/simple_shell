#include "shell.h"

/**
 * remove_comment - clean command from comments
 * @command: string command
 * Return: void
 */
void remove_comment(char *command)
{
	int i = 0;
	char prev = ' ', next = ' ';

	/* place NULL termination at (#) sign */
	for (i = 0; command[i] != '\0'; i++)
	{
		if (command[i + 1])
			next = command[i + 1];
		else
			next = ' ';
		if (command[i] == '#')
		{
			/* check if (#) is not part of a word */
			if (prev == ' ' || next == ' ')
			{
				command[i] = '\0';
				break;
			}
		}
		prev = command[i];
	}
}
