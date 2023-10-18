#include "shell.h"

/**
 * my_strlen - returns string length
 * @s: string
 * Return: length
 */
int my_strlen(char *s)
{
	int y = 0;

	while (*s != '\0')
	{
		y++;
		s++;
	}
	return (y);
}
/**
 * _strdup -  return ptr to new mem
 * @str: input str
 * Return: NULL if str is NULL or success otherwise
 */
char *_strdup(char *str)
{
	size_t u;
	char *copy;

	if (str == NULL)
	{
		return (NULL);
	}
	u = my_strlen(str);
	copy = (char *)malloc((u + 1) * sizeof(char));
	if (copy == NULL)
	{
		return (NULL);
	}
	my_strcpy(copy, str);
	return (copy);
}
