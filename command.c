#include "shell.h"

/**
 * find_executable - Finds the full path of a command in the PATH directories
 * @command: The command to find
 *
 * Return: A pointer to the full path of the command
 * or NULL if not found/executable
 */

char *find_executable(const char *command)
{
	char *path = getenv("PATH");
	char *directories = strdup(path);
	char *token = strtok(directories, ":");
	char *full_path = NULL;
	size_t cmd_len = strlen(command);
	size_t dir_len = strlen(token);

	while (token != NULL)
	{
		full_path = malloc(dir_len + 1 + cmd_len + 1);
	if (!full_path)
	{
		perror("hsh");
		free(directories);
		return (NULL);
	}
	strcpy(full_path, token);
	strcat(full_path, "/");
	strcat(full_path, command);
	if (access(full_path, X_OK) == 0)
	{
		free(directories);
		return (full_path);
	}
	free(full_path);
	token = strtok(NULL, ":");
	}
	free(directories);
	return (NULL);
}

/**
 * run_command - Executes the commands passed by the user
 * @args: The list of commands and arguments the user typed
 *
 * Return: 1 if successful, 0 if not
 */
int run_command(char **args)
{
	pid_t pid;
	int status;
	char *full_path = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("hsh");
		return (0);
	}

	if (pid == 0)
	{
		if (access(args[0], X_OK) == 0)
		{
			full_path = strdup(args[0]);
		}
		else
		{
			full_path = find_executable(args[0]);
		}
		if (full_path != NULL)
		{
			if (execve(full_path, args, NULL) == -1)
			{
				perror("hsh");
				free(full_path);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			perror("hsh");
			exit(EXIT_FAILURE);
		}
			waitpid(pid, &status, 0);
		return (1);
	}
	return (0);
}
