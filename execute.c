#include "shell.h"

/**
 * execute - Func executes command
 * @tokens: tokens
 */
void execute(char **tokens);
void execute(char **tokens)
{
	pid_t pid;
	int status;
	char *envp[] = {"TERM=xterm", NULL};
	char *c_name, *c_path;

	pid = fork();
	if (pid == -1)
	{
		perror("execution of command failed");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		c_name = tokens[0];
		if (strchr(c_name, '/'))
		{
			if (execve(c_name, tokens, envp) == -1)
			{
				perror("execution of command failed");
				_exit(EXIT_FAILURE);
			}
		}
		else
		{
			c_path = search_path(c_name);

			if (c_path == NULL)
			{
				fprintf(stderr, "Command not found: %s\n", c_name);
				exit(EXIT_FAILURE);
			}
			if (execve(c_path, tokens, envp) == -1)
			{
				perror("Command failed");
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
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

/**
 * search_path - Search for command full path
 * @c_name: Command name
 *
 * Return: path to command or NULL if not found
 */
char *search_path(const char *c_name)
{
	char path[1024];
	char *dir;
	const char *find_dir = getenv("PATH");
	char *path_cpy = strdup(find_dir);
	char *path_cpy2 = strdup(path_cpy);

	if (!path_cpy)
	{
		perror("Path not specified");
		return (NULL);
	}
	dir = strtok(path_cpy2, ":");
	while (dir != NULL)
	{
		snprintf(path, sizeof(path), "%s/%s", dir, c_name);
		if (access(path, X_OK) == 0)
		{
			free(path_cpy);
			free(path_cpy2);
			return (strdup(path));
		}
		dir = strtok(NULL, ":");
	}
	free(path_cpy);
	free(path_cpy2);
	return (NULL);
}
