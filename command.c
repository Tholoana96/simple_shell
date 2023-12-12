#include "shell.h"

/**
  * run_command - Executes the commands passed by the user
  * @args: The list of commands and arguments the user typed
  * Return: 1 if successful 0 if not
  */

int run_command(char **args)
{
	pid_t my_pid;
	char *command = args[0];
	int status;

	my_pid = fork();
	if (my_pid == -1)
	{
		perror("hsh");
	}

	if (my_pid == 0)
	{
		if (command[0] == '/' || command[0] == '.')
			command = args[0];
		else
			command = parse_path(command);

		if (!command)
		{
			perror("hsh");
			return (0);
		}

		if (execve(command, args, NULL) == -1)
		{
			perror("hsh");
		}
	}
	else
	{
		wait(&status);
	}
	return (1);
}
