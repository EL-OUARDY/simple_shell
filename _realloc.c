#include "shell.h"

/**
 * _realloc - realloc function for dynamic memory allocation (resize)
 * @ptr: pointer to the previously allocated memory block
 * @size: The new size in bytes
 * Return: pointer to the reallocated memory block on success,
 * or NULL on failure.
 */
void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;
	char *old, *new;
	size_t i;

	if (size <= 0)
	{
		/* If size is 0 or negative, this is equivalent to free(ptr) */
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc((size_t)size); /* Allocate new memory */

	if (new_ptr == NULL)
	{
		/* Allocation failed */
		return (NULL);
	}

	/* Copy data from the old memory block to the new one */
	old = (char *)ptr;
	new = (char *)new_ptr;

	for (i = 0; i < size; i++)
	{
		new[i] = old[i];
	}

	free(ptr); /* Free the old memory block */

	return (new_ptr);
}
