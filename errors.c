#include "shell.h"

/**
 * command_not_found_error - command not found error
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
	_print(shell_info->args[0], STDERR_FILENO);
	_print(": not found\n", STDERR_FILENO);
	_putchar(BUFFER_FLUSH, STDERR_FILENO); /* flush buffer */
	/* set "$?" variable value to 127*/

	free(pn); /* free memory */
}

/**
 * exit_illegal_number_error - exit argument is not a number
 * @shell_info: shell info struct
 * Return: void
 */
void exit_illegal_number_error(shell_info_t *shell_info)
{
	char *pn = int_to_string(shell_info->prompt_number);
	/* {program_name}: {prompt_number}: {command}: Illegal number: {args[1]} */
	_print(shell_info->program_name, STDERR_FILENO);
	_print(": ", STDERR_FILENO);
	_print(pn, STDERR_FILENO); /* print prompt counter */
	_print(": ", STDERR_FILENO);
	_print(shell_info->args[0], STDERR_FILENO);
	_print(": Illegal number: ", STDERR_FILENO);
	_print(shell_info->args[1], STDERR_FILENO);
	_putchar('\n', STDERR_FILENO); /* new line */
	_putchar(BUFFER_FLUSH, STDERR_FILENO); /* flush buffer */
	/* set "$?" variable value to 1 */

	free(pn); /* free memory */
}

/**
 * custom_error_message - show custom error message
 * @message: error message to print
 * @shell_info: shell info struct
 * Return: void
 */
void custom_error_message(char *message, shell_info_t *shell_info)
{
	char *pn = int_to_string(shell_info->prompt_number);

	/* FORMAT: {program_name}: {prompt_number}: {command}: not found */
	_print(shell_info->program_name, STDERR_FILENO);
	_print(": ", STDERR_FILENO);
	_print(pn, STDERR_FILENO); /* print prompt counter */
	_print(": ", STDERR_FILENO);
	_print(message, STDERR_FILENO);
	_putchar(BUFFER_FLUSH, STDERR_FILENO); /* flush buffer */
	/* set "$?" variable value to 1 */

	free(pn); /* free memory */
}
