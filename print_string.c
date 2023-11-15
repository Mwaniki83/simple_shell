#include "shell.h"

/**
* print_env - prints the environment string to stdout
*
* Return: 0
*/
void print_env(void)
{
	int j = 0;
	char **env = environ;

	while (env[j])
	{
		write(STDOUT_FILENO, (const void *)env[j], _strlen(env[j]));
		write(STDOUT_FILENO, "\n", 1);
		j++;
	}
}

