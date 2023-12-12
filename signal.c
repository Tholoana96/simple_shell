#include "shell.h"
/**
* user - Handles signal when user types ctrl + c
* @signal: The signal
*
*/
void user(int signal)
{
(void)signal;
write(STDOUT_FILENO, "\n", 1);
write(STDOUT_FILENO, "$ ", 2);
fflush(stdout);
}
