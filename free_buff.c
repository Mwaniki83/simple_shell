#include "shell.h"

/**
* free_buff - frees buffer after use
* @buff: buffer to be freed
*
* Return: no return
*/
void free_buff(char **buff)
{
	int p = 0;

	if (!buff || buff == NULL)
		return;
	while (buff[p])
	{
		free(buff[p]);
		p++;
	}
	free(buff);
}

