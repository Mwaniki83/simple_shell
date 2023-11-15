#include "shell.h"

/**
 *chk_interract- checks whether shell is in interactive mode or not
 *@h: signal number to show activity
 *Return: nothing
 */

void chk_interract(int p)
{
	(void)p;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}

