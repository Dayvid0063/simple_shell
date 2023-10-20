#include "shell.h"

/**
 * run_cd - Func runs the cd command
 * @tokens: list of tokens
 * Return: List of tokens
 */
int run_cd(char **tokens);
int run_cd(char **tokens)
{
	char *last_pwd = getcwd(NULL, 0);
	char *current_dir = tokens[1] == NULL ||
		strcmp(tokens[1], "~") == 0 ? getenv("HOME") : tokens[1];
	char *absolute_path;

	if (strcmp(tokens[0], "cd") == 0)
	{
		if (strcmp(current_dir, "-") == 0)
		{
			current_dir = getenv("OLDPWD");
			if (!current_dir)
			{
				write(STDOUT_FILENO, "ERROR : Invalid directory\n", 27);
				free(last_pwd);
				return (1);
			}
		}
		if (current_dir[0] != '/')
		{
			absolute_path = malloc(strlen(last_pwd) + strlen(current_dir) + 2);
			if (absolute_path == NULL)
			{
				perror("No such file or directory");
				free(last_pwd);
				return (1);
			}
			snprintf(absolute_path, strlen(last_pwd) + strlen(current_dir)
					+ 2, "%s/%s", last_pwd, current_dir);

			if (chdir(absolute_path) != 0)
			{
				perror("change directory error");
				free(absolute_path);
				free(last_pwd);
				return (1);
			}
			if (strcmp(absolute_path, getenv("OLDPWD")) != 0)
			{
				setenv("OLDPWD", last_pwd, 1);
			}

			free(absolute_path);
		}
		else
		{
			if (chdir(current_dir) != 0)
			{
				perror("change directory error");
				free(last_pwd);
				return (1);
			}
			if (strcmp(current_dir, getenv("OLDPWD")) != 0)
			{
				setenv("OLDPWD", last_pwd, 1);
			}
		}

		free(last_pwd);
		return (1);
	}

	return (0);
}

/**
 * run_setenv - run the setenv command
 * @tokens: the setenv tokens
 * Return: 1 on success and 0 on failure
 */
int run_setenv(char **tokens)
{
	if (tokens[1] == NULL || tokens[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return (1);
	}
	else
	{
		if (setenv(tokens[1], tokens[2], 1) != 0)
		{
			perror("setenv");
			return (1);
		}
	}
	return (1);
}
/**
 * run_unsetenv - run the unsetenv command
 * @tokens: list of tokens
 * Return: 1 on success, 0 on failure
 */
int run_unsetenv(char **tokens)
{
	if (tokens[1] == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return (1);
	}
	else
	{
		if (unsetenv(tokens[1]) != 0)
		{
			perror("unsetenv");
			return (1);
		}
	}
	return (1);
}
/**
 * handle_built_in - Handle built-in commands
 * @tokens: Tokenized command and arguments
 * Return: 1 if a built-in command was handled, 0 otherwise
 */
int handle_built_in(char **tokens)
{

	if (strcmp(tokens[0], "setenv") == 0)
	{
		return (run_setenv(tokens));
	}
	else if (strcmp(tokens[0], "unsetenv") == 0)
	{
		return (run_unsetenv(tokens));
	}
	else if (run_cd(tokens))
	{
		return (1);
	}
	else if (strcmp(tokens[0], "exit") == 0)
	{
		return (run_exit(tokens));
	}
	else if (strcmp(tokens[0], "env") == 0)
	{
		return (run_env());
	}
	return (0);
}
