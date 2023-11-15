#include "shell.h"

/**
* tokenizer - creates tokens from given user input
* @inp: input to be tokenized
*
* Return: array of strings
*/
char **tokenizer(char *inp)
{
	char *buff = NULL, *tbuff = NULL, *token = NULL, *delim = " :\t\r\n";
	char **tokens = NULL;
	int tokensze = 1;
	size_t v = 0, flag = 0;

	buff = _strdup(inp);
	if (!buff)
		return (NULL);
	tbuff = buff;

	while (*tbuff)
	{
		if (_strnch(delim, *tbuff) != NULL && flag == 0)
		{
			tokensze++;
			flag = 1;
		}
		else if (_strnch(delim, *tbuff) == NULL && flag == 1)
			flag = 0;
		tbuff++;
	}
	tokens = malloc(sizeof(char *) * (tokensze + 1));
	token = strtok(buff, delim);
	while (token)
	{
		tokens[v] = _strdup(token);
		if (tokens[v] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
		v++;
	}
	tokens[v] = '\0';
	free(buff);
	return (tokens);
}

