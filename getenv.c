#include "shell.h"

/**
 * my_getenv - Gets val of an env
 * @var: Var name
 *
 * Return: Ptr to the val of var, or NULL if otherwise
 */
char *my_getenv(const char *var)
{
	char *val = NULL;

	while (*environ != NULL)
	{
		if (strncmp(*environ, var, strlen(var)) == 0
				&& (*environ)[strlen(var)] == '=')
		{
			val = *environ + strlen(var) + 1;
			break;
		}
		environ++;
	}

	return (val);
}
