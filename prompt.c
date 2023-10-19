#include "shell.h"
/**
 * read_command - Reads a cmd and displays a prompt
 * @input: Ptr to store input
 * @n: Ptr to size of input
 *
 * Return: Num of chars read, /n char
 */
ssize_t read_command(char **input, size_t *n)
{
	ssize_t read;
	int is_terminal = isatty(STDIN_FILENO);

	if (is_terminal)
	{
		write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);
	}

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

