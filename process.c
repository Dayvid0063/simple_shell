#include "main.h"
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
