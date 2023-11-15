#include "shell.h"
/**
* main -  function to handle the read, execute then print output loop
* @agrc: argument count
* @agrv: argument vector
* @env: environment vector
*
* Return: 0
*/

int main(int agrc, char **agrv, char *env[])
{
	char *line = NULL, *pathcmd = NULL, *path = NULL;
	size_t buffsize = 0;
	ssize_t linesize = 0;
	char **cmd = NULL, **paths = NULL;
	(void)env, (void)agrv;
	if (agrc < 1)
		return (-1);
	signal(SIGINT, chk_interract);
	while (1)
	{
		free_buff(cmd);
		free_buff(paths);
		free(pathcmd);
		user_prompt();
		linesize = getline(&line, &buffsize, stdin);

		if (linesize < 0)
			break;
		info.ln_count++;

		if (line[linesize - 1] == '\n')
			line[linesize - 1] = '\0';
		cmd = tokenize(line);

		if (cmd == NULL || *cmd == NULL || **cmd == '\0')
			continue;
		if (checks(cmd, line))
			continue;
		path = find_path();
		paths = tokenize(path);
		pathcmd = path_test(paths, cmd[0]);

		if (!pathcmd)
			perror(agrv[0]);
		else
			exec(pathcmd, cmd);
	}
	if (linesize < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	return (0);
}

