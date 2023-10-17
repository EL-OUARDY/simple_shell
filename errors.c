#include "shell.h"

/**
 * command_not_found_error - print command not found error
 * @shell_info: shell info struct
 * Return: void
 */
void command_not_found_error(shell_info_t *shell_info)
{
	char *pn = int_to_string(shell_info->prompt_number);

	/* FORMAT: {program_name}: {prompt_number}: {command}: not found */
	_print(shell_info->program_name, STDERR_FILENO);
	_print(": ", STDERR_FILENO);
	_print(pn, STDERR_FILENO); /* print prompt counter */
	_print(": ", STDERR_FILENO);
	_print(shell_info->user_command, STDERR_FILENO);
	_print(": not found\n", STDERR_FILENO);
	_putchar(BUFFER_FLUSH, STDERR_FILENO); /* flush buffer */
	/* set "$?" variable value to 127*/

	free(pn); /* free memory */
}

