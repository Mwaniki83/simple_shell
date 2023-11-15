#include "shell.h"

/**
* _putchar - writes the character c to stdout
* @c:  character to be printed to stdout
*
* Return:  1 for success or -1 for error
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* prnt_str - prints a string
* @s: string to be printed
*
* Return: number of string characters printed
*/
int prnt_str(char *s)
{
	int z = 0;

	while (s[z] != '\0')
	{
		_putchar(s[z]);
		z++;
	}

	return (z);
}

