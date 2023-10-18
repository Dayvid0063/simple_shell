#include "shell.h"
/**
 * execute - Func executes command
 * @tokens: tokens
 */
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
		c_path = search_path(c_name);
		if (execve(c_path, tokens, envp) == -1)
		{
			perror("execution of command failed");
			_exit(EXIT_FAILURE);
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
	char *token;
	char *delimiter = " \t\n";
	char *str_cpy = my_strdup(str);
	char **tokens = malloc(sizeof(char *) * MAX_LINE_LENGTH);
	int count = 0, u;

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
	token = my_strtok(str_cpy, delimiter);
	while (token != NULL)
	{
		tokens[count] = my_strdup(token);

		if (tokens[count] == NULL)
		{
			perror("String tokenizing failed");
			exit(EXIT_FAILURE);
		}
		count++;
		token = my_strtok(NULL, delimiter);
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
	free(str_cpy);
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
	const char *find_dir = my_getenv("PATH");
	char *path_cpy = my_strdup(find_dir);
	char *path_cpy2 = my_strdup(path_cpy);

	if (!path_cpy)
	{
		perror("Path not specified");
		return (NULL);
	}
	dir = my_strtok(path_cpy2, ":");
	while (dir != NULL)
	{
		snprintf(path, sizeof(path), "%s/%s", dir, c_name);
		if (access(path, X_OK) == 0)
		{
			free(path_cpy);
			free(path_cpy2);
			return (my_strdup(path));
		}
		dir = my_strtok(NULL, ":");
	}
	free(path_cpy);
	free(path_cpy2);
	return (NULL);
}