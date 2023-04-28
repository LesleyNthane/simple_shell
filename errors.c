#include "shell.h"

/**
 * _eputs - prints the input string
 * @str: string
 * Return: Nothing
 */
void _eputs(char *str)
{
int i = 0;

if (!str)
return;
while (str[i] != '\0')
{
_eputchar(str[i]);
i++;
}
}

/**
 * _eputchar - writes the character c to stderr
 * @c: character
 * Return: 1
 */
int _eputchar(char c)
{
static int i;
static char buffer[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buffer, i);
i = 0;
}
if (c != BUF_FLUSH)
buffer[i++] = c;
return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @c: character
 * @fd: The filedescriptor to write
 * Return: 1
 */
int _putfd(char c, int fd)
{
static int i;
static char buffer[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(fd, buffer, i);
i = 0;
}
if (c != BUF_FLUSH)
buffer[i++] = c;
return (1);
}

/**
 * _putsfd - prints input string
 * @str: string
 * @fd: the filedescriptor to write
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
int i = 0;

if (!str)
return (0);
while (*str)
{
i += _putfd(*str++, fd);
}
return (i);
}
