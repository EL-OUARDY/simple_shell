#include "shell.h"

/**
 * get_path_list - convert path stirng to linked list
 * Return: a linked list of path directories
 */
path_t *get_path_list()
{
	path_t *head = NULL;
	char *path, *str, *token;

	/* get PATH envirnoment variable */
	path = _getenv("PATH");

	str = _strdup(path);
	token = strtok(str, ":");
	while (token != NULL)
	{
		add_path_node(&head, token);
		token = strtok(NULL, ":");
	}

	/* free ressources */
	free(str);

	return (head);
}

/**
 * add_path_node - add a new path node
 * @head: the head of the targeted list
 * @path: input path string
 * Description: insert a node at the beginning of the targeted list
 * Return: the newly created node
 */
path_t *add_path_node(path_t **head, const char *path)
{
	/* allocate memory for the new node */
	path_t *link = malloc(sizeof(path_t));

	/* failed to allocate memory */
	if (!link)
		return (NULL);

	/* populate the new node */
	link->path = _strdup(path);
	link->next = *head;

	/* the new node become the head of the list */
	*head = link;

	return (link);
}
