#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * my_getline - Reads line input
 * @lineptr: Ptr to buff
 * @n: Ptr to size
 * @m: File stream
 *
 * Return: Num of char
 */
ssize_t my_getline(char **lineptr, size_t *n, FILE *m);
ssize_t my_getline(char **lineptr, size_t *n, FILE *m)
{
	size_t v = 0;
	int c;
	char *temp;

	if (lineptr == NULL || n == NULL)
	{
		write(STDERR_FILENO, "Error! Bad arguments.\n", 22);
		return (-1);
	}

	if (m == NULL)
	{
		write(STDERR_FILENO, "Error! Bad Pointer.\n", 20);
		return (-1);
	}

	if (*lineptr == NULL)
	{
		*n = BUFFER_SIZE;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			write(STDERR_FILENO, "Error allocating memory for the line buffer.\n", 46);
			return (-1);
		}
	}
	(*lineptr)[0] = '\0';

	while ((c = fgetc(m)) != EOF && c != '\n')
	{
		if (v < *n - 1)
		{
			(*lineptr)[v++] = c;
		}
		else
		{

			*n *= 2;
			temp = custom_realloc(*lineptr, *n);
			if (temp == NULL)
			{
				write(STDERR_FILENO,
						"Error reallocating memory for the line buffer.\n", 50);
				return (-1);
			}
			*lineptr = temp;
			(*lineptr)[v++] = c;
		}
	}

	(*lineptr)[v] = '\0';

	return (v);
}
