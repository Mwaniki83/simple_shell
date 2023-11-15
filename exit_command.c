#include "shell.h"

/**
* exit_cmd - handles the exit command to the builtin
* @cmd: the tokenized command
* @inp: input read from stdin
*
* Return: no return
*/
void exit_cmd(char **cmd, char *inp)
{
	free(inp);
	free_buff(cmd);
	exit(0);
}

