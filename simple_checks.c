#include "shell.h"
/**
 *checks- checks whether its a built in function
 *@lin: tokenized user input
 *@buf: line derived from the getline function
 *Return: 1 if input is executed | 0 if otherwise
 */
int checks(char **lin, char *buf)
{
	if (builtin_handler(lin, buf))
		return (1);
	else if (**lin == '/')
	{
		exec(lin[0], lin);
		return (1);
	}
	return (0);
}

