#include "main.h"

/**
 * read_command - read input from the line
 * @line: line pointer
 * @n: line size
 * Return: 0 Always
 */
ssize_t read_command(char **line, size_t *n)
{
	char *request = "$ ";
	size_t read;

	write(1, request, strlen(request));
	read = getline(line, n, stdin);

	return (read);
}

/**
 * split_string - Func split a string into tokens
 * @str: Input string
 */
void split_string(char *str);
void split_string(char *str)
{
	char *token, *trim_str = str, *end;
	char *delimiter = " \t\n";
	char *str_cpy = strdup(str);
	char **tokens = malloc(sizeof(char *) * MAX_LINE_LENGTH);
	int count = 0, u;

	while (*trim_str == ' ' || *trim_str == '\t')
	{
		trim_str++;
	}
	end = trim_str + strlen(trim_str) - 1;
	while (end > trim_str && (*end == ' ' || *end == '\t'))
	{
		*end = '\0';
		end--;
	}

	if (!str_cpy)
	{
		perror("String not available");
		free(str_cpy);
		exit(EXIT_FAILURE);
	}
	if (!tokens)
	{
		perror("No tokens available");
		free(tokens);
		exit(EXIT_FAILURE);
	}
	token = strtok(str_cpy, delimiter);
	while (token != NULL)
	{
		tokens[count] = strdup(token);

		if (tokens[count] == NULL)
		{
			perror("String tokenizing failed");
			exit(EXIT_FAILURE);
		}
		count++;
		token = strtok(NULL, delimiter);
	}
	tokens[count] = NULL;

	if (count > 0)
	{
		execute(tokens);
	}
	for (u = 0; u < count; u++)
	{
		free(tokens[u]);
	}
	free(tokens);
}

/**
 * main - Simple shell main function
 * @arc: argument count
 * @argv: argument value
 * Return: 0 Always
 */
int main(int arc, char **argv)
{
	ssize_t display;
	char *msg = NULL;
	size_t length = 0;

	(void)arc;
	(void)argv;

	while (1)
	{
		display = read_command(&msg, &length);
		if (display == -1)
		{
			break;
		}
		else
		{
			split_string(msg);
		}
	}
	free(msg);
	return (0);
}
