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
	{
		free(array[i]);
	}

	/* free array itself */
	free(array);
}

/**
 * free_path_list - free path list
 * @head: the head of the targeted list
 * Description: free all list nodes from memory
 * Return: void
 */
void free_path_list(path_t **head)
{
	path_t *next_node;

	/* check the head pointer */
	if (head == NULL)
		return;

	while (*head != NULL)
	{
		next_node = (*head)->next;
		free((*head)->path); /* free path string */
		free(*head);         /* free entire node */
		*head = next_node;
	}

	*head = NULL;
}
