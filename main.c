#include "main.h"
/**
 * main - Simple shell main function
 * @arc: argument count
 * @argv: argument value
 * Return: 0 Always
 */
int main(int arc, char **argv)
{
	ssize_t display;
	char *msg = NULL;
	size_t length = 0;

	(void)arc;
	(void)argv;

	while (1)
	{
		display = read_command(&msg, &length);
		if (display == -1)
		{
			break;
		}
		if (msg[0] == '#' || (msg[0] == ' ' && msg[1] == '#'))
		{
			continue;
		}
		split_string(msg);
	}
	free(msg);
	return (EXIT_SUCCESS);
}
