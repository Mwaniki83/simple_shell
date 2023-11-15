#include "shell.h"

/**
 * exec - executes commands entered
 *@cmd: the command entered
 *@lin:vector array of pointers to user commands
 *Return: 0 for success
 */
void exec(char *cmd, char **lin)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
		perror(cmd);
	if (child_pid == 0)
	{
		execve(cmd, lin, env);
		perror(cmd);
		free(cmd);
		free_buff(lin);
		exit(98);
	}
	else
		wait(&status);
}

