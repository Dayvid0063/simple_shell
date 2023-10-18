#include "shell.h"

/**
 * prompt - func sh prompt
 */
void prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
	fflush(stdout);
}

/**
 * read_command - Reads a cmd
 * @input: Ptr to store input
 * @n: Ptr to size of input
 *
 * Return: Num of chars read, /n char
 */
ssize_t read_command(char **input, size_t *n)
{
	return (my_getline(input, n, stdin));
}
