#include "shell.h"

/**
 * _strncmp - compares the first n characters of two strings
 * @str1: string 1
 * @str2: atring 2
 * @n: maximum number of characters to compare
 * Return: an integer value indicating the comparison result
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0 && *str1 && *str2)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
		n--;
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

/**
 * _strcpy - a function that copies a string
 * @dest: copy to
 * @src: copy from
 * Return: result string
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (*(src + l) != '\0')
	{
		l++;
	}
	for (; x < l; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '\0';
	return (dest);
}

/**
 * _strcat - a function that concatenates two strings
 * @dest: destination
 * @src: source
 * Return: a pointer to the destination string
 */
char *_strcat(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (*(dest + l) != '\0')
	{
		l++;
	}
	while (src[x] != '\0')
	{
		dest[l + x] = src[x];
		x++;
	}
	dest[l + x] = '\0';
	return (dest);
}

/**
 * int_to_string - integer to string
 * @number: a given integer
 * Return: string
 */
char *int_to_string(int number)
{
	int i = 0, j = 0, isNegative = 0, numDigits = 1, temp, stringLength, length;
	char *str;

	if (number < 0) /* case of a negative number */
	{
		isNegative = 1;
		number = -number;
	}
	temp = number;

	while (temp >= 10) /* determine the number of digits in the integer */
	{
		numDigits++;
		temp /= 10;
	}
	/* extra 2 bytes for negative sign & null terminator */
	stringLength = numDigits + isNegative + 1;
	str = (char *)malloc(stringLength);

	if (str == NULL) /* memory allocation failed */
		return (NULL);

	do { /* convert the number to a string in reverse order */
		str[i++] = number % 10 + '0';
		number /= 10;
	} while (number > 0);

	if (isNegative) /* add a minus sign for negative numbers */
		str[i++] = '-';
	str[i] = '\0';
	length = i;

	for (j = 0; j < length / 2; j++) /* reverse the string */
	{
		char temp = str[j];

		str[j] = str[length - j - 1];
		str[length - j - 1] = temp;
	}
	return (str);
}

