#include "shell.h"

/**
 * _getline - Read a line of text from a file stream
 * @lineptr: A pointer to a character pointer that will be updated to point
 * to the allocated line buffer
 * @n: A pointer to a size_t variable that will store the size of the buffer
 * @fd: The file descriptor from which to read
 * Return: The number of characters read,
 * or -1 in case of an error or reaching the EOF
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	ssize_t read_chars = 0;
	size_t i = 0;
	char c, *new_line;

	if (lineptr == NULL || n == NULL)
	{
		errno = EINVAL; /* Set error code to indicate invalid arguments */
		return (-1);
	}
	*n = BUFFER_SIZE; /* Initial buffer size */
	if (*lineptr == NULL)
	{
		*lineptr = (char *)malloc(*n); /* Allocate memory for the line */
		if (*lineptr == NULL) /* allocation failed */
			return (-1);
	}
	while (read(fd, &c, 1) > 0)
	{
		if (i >= *n - 1) /* determine if the buffer is close to being full */
		{
			*n *= 2; /* Double the buffer size if it's full */
			new_line = (char *)_realloc(*lineptr, *n); /* resize */
			if (new_line == NULL)
			{
				free(*lineptr);
				return (-1); /* Reallocation failed */
			}
			*lineptr = new_line;
		}
		(*lineptr)[i++] = c; /* Add the character to the line */
		if (c == '\n')
		{
			(*lineptr)[i] = '\0'; /* Null-terminate the line */
			read_chars = i;       /* Set the number of characters read */
			break;
		}
	}
	if (i == 0)
		return (-1); /* No characters read */
	return (read_chars);
}
