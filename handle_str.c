#include "main.h"
void split_string(char *str);
/**
 * split_string - Func split str into tokens
 * @str: Input str
 */
void split_string(char *str)
{
	char *token, *trim_str = str, *end;
	char *delimiter = " \t\n";
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
	if (!tokens)
	{
		perror("No tokens available");
		exit(EXIT_FAILURE);
	}
	token = strtok(trim_str, delimiter);

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
		if (!handle_built_in(tokens))
		{
			execute(tokens);
		}
	}
	for (u = 0; u < count; u++)
	{
		free(tokens[u]);
	}
	free(tokens);
}
