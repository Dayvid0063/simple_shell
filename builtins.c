#include "main.h"
/**
 * run_setenv - run the setenv command
 * @tokens: the setenv tokens
 * Return: 1 on success and 0 on failure
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
 * run_unsetenv - run the unsetenv command
 * @tokens: list of tokens
 * Return: 1 on success, 0 on failure
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
/**
 * handle_built_in - Handle built-in commands
 * @tokens: Tokenized command and arguments
 * Return: 1 if a built-in command was handled, 0 otherwise
 */
int handle_built_in(char **tokens)
{

	if (strcmp(tokens[0], "setenv") == 0)
	{
		return (run_setenv(tokens));
	}
	else if (strcmp(tokens[0], "unsetenv") == 0)
	{
		return (run_unsetenv(tokens));
	}
	else if (strcmp(tokens[0], "env") == 0)
	{
		return (run_env());
	}
	return (0);
}
