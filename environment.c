#include "shell.h"

/**
 * populate_shell_env - initialize shell_info env array from environ
 * @shell_info: shell_info struct
 * Return: void
 */
void populate_shell_env(shell_info_t *shell_info)
{
	int i = 0;
	env_t *head = NULL;

	/* go through the environ array */
	while (environ[i] != NULL)
	{
		add_env_node(&head, environ[i]);
		i++;
	}

	shell_info->env = head;
}

/**
 * _getenv - get an environement variable
 * @name: environement variable key
 * @shell_info: shell_info struct
 * Return: string - environement variable value
 */
char *_getenv(char *name, shell_info_t *shell_info)
{
	int length;
	env_t *head;

	length = _strlen(name);

	/* Loop through the environment variables */
	head = shell_info->env;
	while (head != NULL)
	{
		char *var = head->variable;

		if (_strncmp(var, name, length) == 0 && var[length] == '=')
		{
			/* found a matching environment variable */
			/* skip key part plus (=) sign and return the value part */
			return (var + length + 1);
		}
		head = head->next;
	}

	/* environment variable not found */
	return (NULL);
}

/**
 * _setenv - set/update an environement variable
 * @name: environement variable key
 * @value: environement variable value
 * @shell_info: shell_info struct
 * Return: void
 */
void _setenv(char *name, char *value, shell_info_t *shell_info)
{
	char *var;
	int length;

	/* allocate memory for the new variable */
	/* plus 2 bytes (=) sign and NULL termination */
	length = _strlen(name) + _strlen(value) + 2;
	var = malloc(sizeof(char *) * length);

	if (!var) /* allocation failed */
		return;

	/* remove env variable if already exists */
	_unsetenv(name, shell_info);

	/* construct the new variable */
	_strcpy(var, name);
	_strcat(var, "=");
	_strcat(var, value);

	/* add the new variable to the env linked list */
	add_env_node(&shell_info->env, var);

	/* free variable */
	free(var);
}

/**
 * _unsetenv - remove an environement variable
 * @name: environement variable key
 * @shell_info: shell_info struct
 * Return: (1) if removed (-1) not found
 */
int _unsetenv(char *name, shell_info_t *shell_info)
{
	env_t *current_node;
	env_t *prev_node;
	int length;
	char *var;

	length = _strlen(name);

	current_node = shell_info->env;
	var = current_node->variable;

	/* check if target is the head node */
	if (_strncmp(var, name, length) == 0 && var[length] == '=')
	{
		shell_info->env = (shell_info->env)->next;
		/* delete node */
		free(current_node->variable);
		free(current_node);
		return (1);
	}

	/* go through the list*/
	while (current_node)
	{
		var = current_node->variable;

		if (_strncmp(var, name, length) == 0 && var[length] == '=')
		{ /* target node found */
			prev_node->next = current_node->next;
			/* delete node */
			free(current_node->variable);
			free(current_node);
			return (1);
		}
		prev_node = current_node;
		current_node = current_node->next;
	}

	return (-1); /* not found */
}
