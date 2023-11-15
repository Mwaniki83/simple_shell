#include "shell.h"

/**
* append_path - adds path to a specific command
* @pth: path of command
* @cmd: the command entered by user
*
* Return: the buffer containing command with path, NULL if it fails
*/
char *append_path(char *pth, char *cmd)
{
	char *buff;
	size_t a = 0, b = 0;

	if (cmd == NULL)
		cmd = "";

	if (pth == NULL)
		pth = "";

	buff = malloc(sizeof(char) * (_strlen(pth) + _strlen(cmd) + 2));

	if (!buff)
		return (NULL);

	while (pth[a])
	{
		buff[a] = pth[a];
		a++;
	}

	if (pth[a - 1] != '/')
	{
		buff[a] = '/';
		a++;
	}
	while (cmd[b])
	{
		buff[a + b] = cmd[b];
		a++;
		b++;
	}
	buff[a + b] = '\0';
	return (buff);
}

