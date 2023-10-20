#include "main.h"

/**
 * run_env - Runs env command
 *
 * Return: 1
 */
int run_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}
