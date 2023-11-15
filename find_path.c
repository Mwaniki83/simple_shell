#include "shell.h"

/**
* find_path - traverse the entire environment to find the specificpath
* Return: path or NULL if it is not found
*/
char *find_path(void)
{
	int x;
	char **env = environ, *pth = NULL;

	while (*env)
	{
		if (_compstr(*env, "PATH=", 5) == 0)
		{
			pth = *env;
			while (*pth && x < 5)
			{
				pth++;
				x++;
			}
			return (pth);
		}
		env++;
	}
	return (NULL);
}
