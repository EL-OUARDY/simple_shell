#include "shell.h"

/**
 * free_all_ressources - free ressources
 * @shell_info: shell information
 * Description: free the allocated memory by the shell
 * Return: void
 */
void free_all_ressources(shell_info_t *shell_info)
{
	/* free user command string */
	free(shell_info->user_command);

	/* free arguments array */
	free_array(shell_info->args);

	/* free env array */
	free_env_list(&shell_info->env);
}

/**
 * free_array - free an array of strings
 * @array: the array to be freed
 * Description: free the allocated memory space of a given array
 * Return: void
 */
void free_array(char **array)
{
	int i, length = 0;

	/* array length */
	while (array[length])
		length++;

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

/**
 * free_env_list - free env list
 * @head: the head of the targeted list
 * Description: free all list nodes from memory
 * Return: void
 */
void free_env_list(env_t **head)
{
	env_t *next_node;

	/* check the head pointer */
	if (head == NULL)
		return;

	while (*head != NULL)
	{
		next_node = (*head)->next;
		free((*head)->variable); /* free path string */
		free(*head);             /* free entire node */
		*head = next_node;
	}

	*head = NULL;
}

