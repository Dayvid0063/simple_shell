#include "shell.h"
/**
 * my_strcspn - Func gets length of initial substr
 * @s: Str
 * @n: Chars set
 *
 * Return: Length
 */
size_t my_strcspn(const char *s, const char *n)
{
	const char *u, *v;
	size_t num = 0;

	for (u = s; *u != '\0'; ++u)
	{
		for (v = n; *v != '\0'; ++v)
		{
			if (*u == *v)
			{
				return (num);
			}
		}
		++num;
	}

	return (num);
}
/**
 * my_strtok - tokenize input str
 * @str: input str
 * @delim: delimiter str
 * Return: Next token or NULL
 */
char *my_strtok(char *str, const char *delim)
{
	static char *buf;
	char *tok;
	const char *u = delim;

	if (str != NULL)
	{
		buf = str;
	}
	if (buf == NULL || *buf == '\0')
	{
		return (NULL);
	}
	tok = buf;
	while (*buf != '\0')
	{

		while (*u != '\0')
		{
			if (*buf == *u)
			{
				*buf = '\0';
				buf++;
				if (tok != buf)
				{
					return (tok);
				}
				else
				{
					tok = buf;
					break;
				}
			}
			u++;
		}
		buf++;
	}
	return (tok);
}
