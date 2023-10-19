#include "shell.h"
/**
 * simple_shell - Func runs shell
 */
void simple_shell(void)
{
	char *input = NULL;
	size_t n = 0;
	ssize_t read_n;

	while (1)
	{
		prompt();
		read_n = read_command(&input, &n);
		if (read_n == -1)
		{
			break;
		}
		if (input[0] == '#')
		{
			continue;
		}
		input[strcspn(input, "\n")] = 0;
		if (strlen(input) == 0)
		{
			continue;
		}
		else
		{
			split_string(input);
		}
	}
	free(input);
}
