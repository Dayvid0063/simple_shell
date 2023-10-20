#include "shell.h"
/**
 * read_command - read input from the line
 * @line: line pointer
 * @n: line size
 * Return: 0 Always
 */
ssize_t read_command(char **line, size_t *n)
{
	int is_interactive = isatty(STDIN_FILENO);
	char *request;
	ssize_t read;

	if (is_interactive)
	{
		request = "$ ";
		write(1, request, strlen(request));
	}
	read = getline(line, n, stdin);

	if (!is_interactive && read == -1)
	{
		return (-1);
	}
	if (is_interactive && read == -1)
	{
		return (-1);
	}
	if (is_interactive && read > 0 && (*line)[read - 1] == '\n')
	{
		(*line)[read - 1] = '\0';
		read--;
	}

	return (read);
}

