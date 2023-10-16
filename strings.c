#include "shell.h"

/**
 * print_shell_prompt - display a prompt for the user
 * @str: string to use as prompt
 *
 * Return: void
 */
void print_shell_prompt(char *str)
{
	_print(str, STDOUT_FILENO);
	_putchar(BUFFER_FLUSH, STDOUT_FILENO); /* flush buffer */
}

/**
 * _print - print a string to appropriate file descriptor
 * @str: string to print
 * @fd: target file descriptor
 *
 * Return: void
 */
void _print(const char *str, int fd)
{
	int i = 0;

	if (!str)
		return;

	while (str[i] != '\0')
	{
		_putchar(str[i], fd);
		i++;
	}
}

/**
 * _putchar - writes the character to appropriate file descriptor
 * @c: The character to print
 * @fd: target file descriptor
 *
 * Return: success (1) - error (-1)
 */
int _putchar(char c, int fd)
{
	static int buffer_counter;
	static char buffer[BUFFER_SIZE];

	/* flush the buffer if it is full OR if the character c is BUFFER_FLUSH */
	if (c == BUFFER_FLUSH || buffer_counter >= BUFFER_SIZE)
	{
		write(fd, buffer, buffer_counter); /* write to the fd */
		buffer_counter = 0;                /* reset buffer */
	}

	if (c != BUFFER_FLUSH)
		buffer[buffer_counter++] = c; /* save c to the buffer */

	return (1);
}

/**
 * _strlen - output the length of a string
 * @s: string
 * Return: int - the lenght of the given string
 */
int _strlen(const char *s)
{
	int l = 0;

	while (*s++)
		l++;

	return (l);
}

/**
 * _strcmp - a function that compare two strings
 * @s1: string 1
 * @s2: atring 2
 * Return: an integer indicates the difference between s1 & s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
