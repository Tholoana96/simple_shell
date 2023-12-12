#include "shell.h"

/**
  * tokenizer - Tokenize the PATH to return a list of folders
  * @path: The path string to convert to an array
  * Return: An array of the directories
  */

char **tokenizer(char *path)
{
	char *copyof_path = path;
	int i = 0;
	char *token;
	static char *arr[20] = {NULL};

	if (path == NULL)
		return (NULL);

	token = strtok(copyof_path, ":");
	while (token != NULL)
	{
		arr[i++] = token;
		token = strtok(NULL, ":");
	}
	return (arr);
}
