#include "shell.h"

/**
 * _getenv - get environement variable
 * @name: environement variable key
 * Return: string - environement variable value
 */
char *_getenv(char *name)
{
	int i = 0;
	int length;

	length = _strlen(name);

	/* Loop through the environment variables */
	while (environ[i])
	{
		char *var = environ[i];

		if (_strncmp(var, name, length) == 0 && var[length] == '=')
		{
			/* found a matching environment variable */
			/* skip key part plus (=) sign and return the value part */
			return (var + length + 1);
		}
		i++;
	}

	/* environment variable not found */
	return (NULL);
}
