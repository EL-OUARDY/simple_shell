#include "shell.h"

/**
 * free_array - free an array of strings
 * @array: the array to be freed
 * @length: array element length
 * Description: free the allocated memory space of a given array
 * Return: void
 */
void free_array(char **array, int length)
{
	int i;

	/* free each array element */
	for (i = 0; i < length; i++)
		free(array[i]);

	/* free array itself */
	free(array);
}
