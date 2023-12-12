#include "shell.h"
/**
* _readline - Reads the user input from standard input
*
* Return: The line that was read if successful and NULL if it failed
*/
char *_readline(void)
{
char *line = NULL;
size_t bufsize = 0;
int len = 0;
len = getline(&line, &bufsize, stdin);
if (len == -1)
{
free(line);
write(STDOUT_FILENO, "\n", 1);
return (NULL);
}
if (line[len - 1] == '\n')
line[len - 1] = '\0';
return (line);
}

#include "shell.h"
#define BUFFSIZE 1024
/**
* _splitline - Splits a line passed to it and stores the words into an array
* @line: The line to be split
*
* Return: The array of tokens if successful
*/
char **_splitline(char *line)
{
int bufsize = BUFFSIZE, p = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;
if (!tokens)
{
perror("hsh");
exit(EXIT_FAILURE);
}
token = strtok(line, " ");
while (token != NULL)
{
tokens[p] = token;
p++;
token = strtok(NULL, " ");
}
tokens[p] = NULL;
return (tokens);
}

