#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/* handle built in functions */
int checks(char **lin, char *buff);
void user_prompt(void);
void chk_interract(int p);
char **tokenizer(char *inp);
char *path_test(char **pth, char *cmd);
char *append_path(char *pth, char *cmd);
int builtin_handler(char **cmd, char *inp);
void exit_cmd(char **cmd, char *inp);

void print_env(void);

/* string handlers */
int _stcheck(char *st1, char *st2);
int _strlen(char *s);
int _compstr(char *st1, char *st2, int n);
char *_strdup(char *st);
char *_strnch(char *s, char c);

void exec(char *cmd, char **inp);
char *find_path(void);

/* util functions */
void free_buff(char **buff);

struct builtin
{
	char *env;
	char *exit;
} builtin;

struct info
{
	int final_exit;
	int ln_count;
} info;

struct flags
{
	bool interactive;
} flags;

#endif

