#include "main.h"
/**
 * execute - Func executes cmd
 * @tokens: Tokens
 */
void execute(char **tokens);
void execute(char **tokens)
{
	pid_t pid;
	int status;
	char *c_name, *c_path;
	char *envp[] = {"TERM=xterm", NULL};

	pid = fork();
	if (pid == -1)
	{
		perror("execution of command failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		c_name = tokens[0];

		if (strchr(c_name, '/'))
		{
			if (execve(c_name, tokens, envp) == -1)
			{
				perror("execution of command failed");
				exit(EXIT_FAILURE);
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
