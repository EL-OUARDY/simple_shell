#include "shell.h"

/**
 * get_path_list - convert path stirng to linked list
 * @shell_info: shell info struct
 * Return: a linked list of path directories
 */
path_t *get_path_list(shell_info_t *shell_info)
{
	path_t *head = NULL;
	char *path, *str, *token;

	/* get PATH envirnoment variable */
	path = _getenv("PATH", shell_info);

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

/**
 * add_env_node - add a new env node
 * @head: the head of the targeted list
 * @variable: input variable string
 * Description: insert a node at the beginning of the targeted list
 * Return: the newly created node
 */
env_t *add_env_node(env_t **head, const char *variable)
{
	/* allocate memory for the new node */
	env_t *link = malloc(sizeof(env_t));

	/* failed to allocate memory */
	if (!link)
		return (NULL);

	/* populate the new node */
	link->variable = _strdup(variable);
	link->next = *head;

	/* the new node become the head of the list */
	*head = link;

	return (link);
}

/**
 * env_list_to_array - convert env list to a simple string array
 * @head: the head of the targeted list
 * Return: the newly created node
 */
char **env_list_to_array(env_t *head)
{
	int i, count = 0;
	env_t *current;
	char **array;

	/* count the number of elements in the linked list */
	current = head;
	while (current)
	{
		count++;
		current = current->next;
	}

	/* allocate memory for the array of strings */
	array = (char **)malloc(sizeof(char *) * (count + 1));

	if (!array)
	{
		perror("Error");
		return (NULL);
	}

	/* copy the linked list elements to the array */
	current = head;
	for (i = 0; i < count; i++)
	{
		array[i] = _strdup(current->variable);
		current = current->next;
	}

	/* add a NULL terminator at the end of the array */
	array[count] = NULL;

	return (array);
}
