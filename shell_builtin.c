#include "shell.h"

/**
* builtin_handler - handles the execution of builtin functions
* @cmd: tokenized commands
* @inp: input read from stdin
*
* Return: 1 if executed | 0 if it is not
*/
int builtin_handler(char **cmd, char *inp)
{
	struct builtin builtin = {"env", "exit"};

	if (_stcheck(*cmd, builtin.env) == 0)
	{
		print_env();
		return (1);
	}
	else if (_stcheck(*cmd, builtin.exit) == 0)
	{
		exit_cmd(cmd, inp);
		return (1);
	}
	return (0);
}

