#include "main.h"
/**
 * run_exit - runs the exit command
 * @tokens: list of tokens
 * Return: 1 on success
 */
int run_exit(char **tokens)
{
	if (tokens[1] != NULL)
	{
		char *endptr;
		long status = strtol(tokens[1], &endptr, 10);

		if (*endptr != '\0')
		{
			fprintf(stderr, "Usage: exit status, where status is an integer\n");
		}
		else
		{
			exit((int)status);
		}
	}
	else
	{
		exit(0);
	}
	return (1);
}

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
