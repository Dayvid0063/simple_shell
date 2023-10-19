#include "shell.h"
/**
 * prompt - func sh prompt
 */
void prompt(void)
{
	int is_terminal = isatty(STDIN_FILENO);

	if (is_terminal)
	{
		write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);
	}
}

/**
 * read_command - Reads a cmd.
 * @input: Ptr to store input
 * @n: Ptr to size of input
 *
 * Return: Num of chars read, /n char
 */
ssize_t read_command(char **input, size_t *n)
{
	int is_terminal = isatty(STDIN_FILENO);
	ssize_t read;

	read = getline(input, n, stdin);
	if (!is_terminal && read == -1)
	{
		return (-1);
	}

	if (is_terminal && read == -1)
	{
		return (-1);
	}

	if (is_terminal && read > 0 && (*input)[read - 1] == '\n')
	{
		(*input)[read - 1] = '\0';
		read--;
	}

	return (read);
}
