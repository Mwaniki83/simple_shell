#include "shell.h"

/**
* path_test - checks whether a specifiedpath is valid
* @pth: tokenized path
* @cmd: user entered command
*
* Return: path appended with command on success
* NULL on failure
*/
char *path_test(char **pth, char *cmd)
{
	int y = 0;
	char *output;

	while (pth[y])
	{
		output = append_path(pth[y], cmd);
		if (access(output, F_OK | X_OK) == 0)
			return (output);
		free(output);
		y++;
	}
	return (NULL);
}

