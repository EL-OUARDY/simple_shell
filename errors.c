#include "shell.h"

/**
 * command_not_found_error - print command not found error
 * @command: string command
 * @info: shell info struct
 * Return: void
 */
void command_not_found_error(char *command, shell_info_t *info)
{
	char *pn = int_to_string(info->prompt_number);
	/* FORMAT: {program_name}: 1: {command}: not found */
	_print(info->program_name, STDERR_FILENO);
	_print(": ", STDERR_FILENO);
	_print(pn, STDERR_FILENO); /* print prompt counter */
	_print(": ", STDERR_FILENO);
	_print(command, STDERR_FILENO);
	_print(": not found\n", STDERR_FILENO);
	_putchar(BUFFER_FLUSH, STDERR_FILENO); /* flush buffer */
	/* set "$?" variable value to 127*/

	free(pn); /* free memory */
}
