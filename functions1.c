#include <unistd.h>

/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}
#include "shell.h"
/**
* _strcat - Concatenates two strings passed to it
* @dest: The destination string
* @src: The string to be added
*
* Return: Pointer to the new string
*/
char *_strcat(char *dest, char *src)
{
int length, j;
length = 0;
while (dest[length] != '\0')
length++;
for (j = 0; src[j] != '\0'; j++, length++)
dest[length] = src[j];
dest[length] = '\0';
return (dest);
}

#include "shell.h"
/**
* _strcmp - A function to compare two strings
* @s1: First string
* @s2: Second string
*
* Return: 0 if equal, negative value if less than & positive if greater than
*/
int _strcmp(char *s1, char *s2)
{
int i = 0, j;

for (i = 0; s1[i] && s2[i]; i++)
{
if (s1[i] == s2[i])
continue;
else
break;
}
j = s1[i] - s2[i];
return (j);
}
