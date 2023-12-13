#include "shell.h"

/**
 * command_path - Resolves the full path for a command
 * based on directories
 *
 * @command: The command to resolve
 * @directories: Array of directories to search in
 *
 * Return: A pointer to the full path of the command
 * or NULL if not found/executable
 */

char *command_path(const char *command, char **directories)
{
	char *full_path = NULL;
	int i = 0;
	size_t len_dir = 0;
	size_t len_cmd = strlen(command);

	while (directories[i] != NULL)
	{
		char *token = directories[i];

		len_dir = strlen(token);
		full_path = malloc(len_dir + 1 + len_cmd + 1);
	if (!full_path)
	{
		perror("hsh");
		return (NULL);
	}
	strcpy(full_path, directories[i]);
	strcat(full_path, "/");
	strcat(full_path, command);

	if (access(full_path, X_OK) == 0)
	{
		return (full_path);
	}
	free(full_path);
	full_path = NULL;
	}

	return (full_path);
}
