#include "shell.h"

/**
 * is_numeric - check a string if it is valid number
 * @str: string to use
 *
 * Return: (1) numeric, (0) not numeric
 */
int is_numeric(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0); /* empty string is not numeric. */

	/* handle an optional minus sign at the beginning. */
	if (*str == '-')
		str++; /* move past the minus sign. */

	while (*str) /* if any character is not a digit, it's not numeric. */
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}

	return (1); /* all characters are digits, so it's numeric. */
}

/**
 * _atoi - convert string to a number
 * @str: string to convert
 *
 * Return: integer, (0) failed to convert
 */
int _atoi(const char *str)
{
	int result = 0;
	int sign = 1; /* 1 for positive, -1 for negative */

	if (*str == '-')
	{
		sign = -1;
		str++; /* Move past the minus sign */
	}

	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0); /* string is not a valid number */
		result = result * 10 + (*str - '0');
		str++;
	}

	return (result * sign);
}
