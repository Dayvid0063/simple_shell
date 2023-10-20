#include "main.h"
/**
 * run_setenv - Func run setenv
 * @tokens: Tokens
 * Return: 1 on success, 0 otherwise
 */
int run_setenv(char **tokens)
{
	if (tokens[1] == NULL || tokens[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return (1);
	}
	else
	{
		if (setenv(tokens[1], tokens[2], 1) != 0)
		{
			perror("setenv");
			return (1);
		}
	}
	return (1);
}
/**
 * run_unsetenv - Func run unsetenv
 * @tokens: Tokens
 * Return: 1 on success, 0 otherwise
 */
int run_unsetenv(char **tokens)
{
	if (tokens[1] == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return (1);
	}
	else
	{
		if (unsetenv(tokens[1]) != 0)
		{
			perror("unsetenv");
			return (1);
		}
	}
	return (1);
}
