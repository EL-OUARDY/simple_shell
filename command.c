#include "shell.h"

/**
 * process_command - handle different type of shell commands
 * @shell_info: shell info struct
 * Return: void
 */
void process_command(shell_info_t *shell_info)
{
	char *validated;

	/* split command into command/args array */
	shell_info->args_count = argument_count(shell_info->user_command);
	shell_info->args = split_command(shell_info);

	/* handle builtin commands */
	if (call_builtin_handler_func(shell_info) == 1)
		return; /* return, builtin executed */

	/* check if the command exists in any PATH directories */
	validated = validate_command(shell_info->args[0]);

	if (validated == NULL) /* command not found */
	{
		command_not_found_error(shell_info);
		free_array(shell_info->args, shell_info->args_count); /* free arguments */
		/* TODO: set status code */
		return;
	}
	else
	{
		/* change command with the validated one */
		free(shell_info->args[0]);
		shell_info->args[0] = validated;
	}

	/* run the command in a child process */
	execute_child_process(shell_info);

	free_array(shell_info->args, shell_info->args_count); /* free arguments */
}

/**
 * execute_child_process - fork a child process to execute our shell command
 * @shell_info: shell info struct
 * Return: void
 */
void execute_child_process(shell_info_t *shell_info)
{
	pid_t child_pid;

	child_pid = fork(); /* fork a child process */

	/* faild to create child process */
	if (child_pid == -1)
	{
		perror("Error:");
		free(shell_info->user_command);           /* free command variable */
		free_array(shell_info->args, shell_info->args_count); /* free arguments */
		exit(1);
	}

	if (child_pid == 0) /* child process */
	{
		if (execve(shell_info->args[0], shell_info->args, environ) == -1)
		{
			perror("Error:");
			free(shell_info->user_command);           /* free command variable */
			free_array(shell_info->args, shell_info->args_count); /* free arguments */
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{ /* parent process */
		int status;

		waitpid(child_pid, &status, 0);
		/* set status code */
	}
}

/**
 * validate_command - validate the command
 * @command: command string
 * Return: on success: if command exist return the fullpath command
 * on error : return NULL means command not exist
 */
char *validate_command(char *command)
{
	char *fullpath_cmd = NULL;
	path_t *path_list = NULL, *head;

	/* check if command is valid */
	if (is_command_exists(command) == 1)
		return (_strdup(command));

	/* NOT exist */
	/* convert path string to linked list */
	path_list = get_path_list();

	/* look in PATH directories */
	head = path_list;

	while (head != NULL) /* go through each directory */
	{
		char *current_path = head->path;

		fullpath_cmd = command_fullpath(current_path, command);

		/* check if command is located in this directory */
		if (is_command_exists(fullpath_cmd) == 1)
		{
			free_path_list(&path_list); /* free path_list */
			return (fullpath_cmd);
		}

		free(fullpath_cmd); /* free fullpath_cmd */
		head = head->next;  /* check next directory */
	}

	/* free ressources */
	free_path_list(&path_list);
	return (NULL);
}

/**
 * is_command_exists - determines if a command exists and it is executable
 * @path: path to the file
 * Return: (1) if true, (0) if not
 */
int is_command_exists(const char *path)
{
	struct stat file_stat;

	if (access(path, X_OK) != -1)
	{ /* path exists and has permission */
		/* check if the file is executable */
		if (stat(path, &file_stat) == 0 && (file_stat.st_mode & S_IFREG))
			return (1);
	}
	return (0);
}

/**
 * command_fullpath - get command full path
 * @path: string path
 * @command: command
 * Return: a full path string to the command
 */
char *command_fullpath(char *path, char *command)
{
	char *fullpath;
	int length;

	/* fullpath length +2 for (/) character & NULL termination */
	length = _strlen(path) + _strlen(command) + 2;

	fullpath = malloc(sizeof(char) * length);

	if (fullpath == NULL) /* allocation failed */
		return (NULL);

	_strcpy(fullpath, path);
	_strcat(fullpath, "/");
	_strcat(fullpath, command);

	return (fullpath);
}

