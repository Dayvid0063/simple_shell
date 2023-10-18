#include "shell.h"

/**
 * get_path - Get each directory in PATH env
 */
void get_path(void)
{
	char *token, *path = my_getenv("PATH");

	if (path == NULL)
	{
		write(STDERR_FILENO, "PATH environment variable not set\n", 35);
		return;
	}

	token = my_strtok(path, ":");

	while (token != NULL)
	{
		write(STDOUT_FILENO, token, my_strlen(token));
		write(STDOUT_FILENO, "\n", 1);
		token = my_strtok(NULL, ":");
	}
}
