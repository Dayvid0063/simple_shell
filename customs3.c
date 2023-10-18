#include "shell.h"
/**
 * my_strcmp - function that compare two strings
 * @s1: value input
 * @s2: value input
 *
 * Return: s1[i] - s2[i]
 */
int my_strcmp(char *s1, char *s2)
{
	int f = 0;

	while (s1[f] != '\0' && s2[f] != '\0')
	{
		if (s1[f] != s2[f])
		{
			return (s1[f] - s2[f]);
		}
		f++;
	}
	return (0);
}
/**
 * my_strncmp - Compare chars of two str
 * @s1: 1st str
 * @s2: 2nd str
 * @n: Max num chars to compare
 *
 * Return: An int
 */
int my_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- > 0)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}

		if (*s1 == '\0')
		{
			break;
		}

		s1++;
		s2++;
	}

	return (0);
}
