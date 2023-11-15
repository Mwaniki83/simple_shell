#include "shell.h"

/**
* _stcheck - compares two strings
* @st1: first string to compare
* @st2: second string to compare
*
* Return: Difference between the two strings
*/
int _stcheck(char *st1, char *st2)
{
	int i = 0, output;

	while (*(st1 + i) == *(st2 + i) && *(st1 + i) != '\0')
		i++;

	output = (*(st1 + i) - *(st2 + i));

	return (output);
}

/**
* _strlen - returns the length of a string
* @s: string to check
*
* Return: length of the string
*/
int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

/**
* _compstr - compares two strings up to n bytes
* @st1: first string compared
* @st2: second string compared
* @n: number of bytes
*
* Return: difference between the two
*/
int _compstr(char *st1, char *st2, int n)
{
	int y;

	for (y = 0; st1[y] && st2[y] && y < n; y++)
	{
		if (st1[y] != st2[y])
			return (st1[y] - st2[y]);
	}
	return (0);
}

/**
* _strdup - dupicates a string
* @st: string to be duplicated
*
* Return: pointer to duplicated string
*/
char *_strdup(char *st)
{
	char *point;
	int y, leng;

	if (st == NULL)
		return (NULL);

	leng = _strlen(st);

	point = malloc(sizeof(char) * (leng + 1));
	if (!point)
		return (NULL);
	for (y = 0; *st != '\0'; st++, y++)
		point[y] = st[0];

	point[y++] = '\0';
	return (point);
}

/**
* _strnch - find a character within a string
* @s: string to be checked
* @c: character to be found
*
* Return: pointer to first location of character
* NULL if character not found
*/
char *_strnch(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (!c)
		return (s);
	return (NULL);
}

