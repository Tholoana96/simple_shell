#include "shell.h"

/**
 * shell_environ - finds the environment variable requested by user
 * @name: environment variable requested by user
 * Return: value of the environment variable
 */

char *shell_environ(char *name)
{
	int i, len;

	len = _strlen(name);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], name, len) == 0)
			return (environ[i] + len + 1);
	}
	return (NULL);
}

#include "shell.h"

/**
  * _displayenv - Prints all the environment variables
  *
  */

void _displayenv(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		size_t len = strlen(environ[i]);

		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
}
