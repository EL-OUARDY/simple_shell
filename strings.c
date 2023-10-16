#include "shell.h"

/**
 * print_string - print a string to the console
 * @str: string to print
 *
 * Return: void
 */
void print_string(const char *str)
{
	size_t length;

	length = _strlen(str);

	write(STDOUT_FILENO, str, length);
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
 * Return: a an integer indicates the difference between s1 & s2
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

/**
 * _strdup - duplicate a string
 * @str: the string to duplicate.
 *
 * Return: a duplicated string or NULL if memory allocation fails.
 */
char *_strdup(const char *str)
{
	int i, len = 0;
	char *duplicate;

	if (str == NULL)
	{
		return (NULL); /* Handle NULL input gracefully */
	}

	len = _strlen(str) + 1; /* Include space for the null terminator */
	duplicate = (char *)malloc(len);

	if (duplicate != NULL)
	{
		for (i = 0; i < len; i++)
		{
			duplicate[i] = str[i];
		}
	}

	return (duplicate);
}
