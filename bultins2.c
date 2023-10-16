#include "shell.h"
/**
 * _setenv - Initialize a new environment variable,
 * or modify an existing one.
 * @command: the builtin command.
 * @argv: arguments.
 * @status: exit status.
 * @idx: index of the command.
 * @new_env: new_environment variable.
 * Return: (void)
*/
void _setenv(char **command, char **argv, int *status, int idx,
char **new_env)
{
	int i;
	char *key, *variable, *tmp, *new;
	(void) idx;
	(void) argv;

	if (!command[1] || !command[2])
	{
		free2Darray(command), (*status) = 0;
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, command[1]) == 0)
		{
			variable = strtok(NULL, "\n");
			if (_strcmp(variable, command[2]) == 0)
			{
				free(tmp), free2Darray(command), (*status) = 0;
				return;
			}
			_strcpy(environ[i], command[1]);
			_strcat(environ[i], "=");
			_strcat(environ[i], command[2]);
			free(tmp), free2Darray(command), (*status) = 0;
			return;
		}
		free(tmp), tmp = NULL;
	}
	new = malloc(_strlen(command[1]) + _strlen(command[2]) + 2);
	_strcpy(new, command[1]);
	_strcat(new, "=");
	_strcat(new, command[2]);
	environ[i] = new, environ[i + 1] = NULL;
	(*new_env) = new;
	(*status) = 0, free2Darray(command);
}
/**
 * _unsetenv - Remove an environment variable.
 * @command: the builtin command.
 * @argv: arguments.
 * @status: exit status.
 * @idx: index of the command.
 * @new_env: new_environment variable.
 * Return: (void)
*/
void _unsetenv(char **command, char **argv, int *status, int idx,
char **new_env)
{
	int i;
	char *tmp, *key;
	(void) idx;
	(void) argv;
	(void) new_env;

	if (command[1])
	{
		for (i = 0; environ[i]; i++)
		{
			tmp = _strdup(environ[i]);
			key = strtok(tmp, "=");
			if (_strcmp(command[1], key) == 0)
			{
				free(tmp), tmp = NULL;
				break;
			}
			free(tmp), tmp = NULL;
		}
		while (environ[i])
		{
			environ[i] = environ[i + 1];
			i++;
		}
	}
	(*status) = 0;
	free2Darray(command);
}

/**
 * change_directory - change directory to given path.
 * @command: the builtin command.
 * @argv: arguments.
 * @status: exit status.
 * @idx: index of the command.
 * @new_env: new_environment variable.
 * Return: (void)
*/
void change_directory(char **command, char **argv, int *status, int idx,
char **new_env)
{
	char *HOME, *OLDPWD, current_wd[1024];

	getcwd(current_wd, 1024);
	if (!command[1])
	{
		HOME = _getenv("HOME");
		if (!HOME)
		{
			free2Darray(command), (*status) = 0;
			return;
		}
		chdir(HOME), set_wd_env("PWD", HOME, new_env);
		free(HOME);
	}
	else if (_strcmp(command[1], "-") == 0)
	{
		OLDPWD = _getenv("OLDPWD");
		if (!OLDPWD)
		{
			write(STDOUT_FILENO, current_wd, _strlen(current_wd));
			write(STDOUT_FILENO, "\n", 1);
			free2Darray(command), (*status) = 0;
			return;
		}
		chdir(OLDPWD), set_wd_env("PWD", OLDPWD, new_env);
		write(STDOUT_FILENO, OLDPWD, _strlen(OLDPWD));
		write(STDOUT_FILENO, "\n", 1);
		free(OLDPWD);
	}
	else if (chdir(command[1]) == -1)
		print_cd_error(argv[0], idx, command[1]);
	else
		set_wd_env("PWD", command[1], new_env);

	free2Darray(command), (*status) = 0;
	set_wd_env("OLDPWD", current_wd, new_env);
}
