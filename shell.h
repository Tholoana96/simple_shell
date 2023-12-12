#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
extern char **environ;
char *_readline(void);
char **_splitline(char *line);
int run_command(char **args);
char *parse_path(char *command);
char *_strcat(char *dest, char *src);
char **tokenizer(char *path);
int _strcmp(char *s1, char *s2);
void user(int signal);
int _putchar(char c);
char *shell_environ(char *name);
void _displayenv(void);
int _strlen(char *s);
int _strncmp(char *str1, char *str2, int n);
#endif
