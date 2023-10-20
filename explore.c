#include "main.h"
/**
 * search_path - Search for cmd full path
 * @c_name: Cmd name
 *
 * Return: Path to cmd,NULL if not found
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
