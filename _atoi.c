#include "shell.h"

/**
 * interactive - return 1 when shell is interactive
 * @info: structure
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @c: the character to check
 * @delim: the delimeter
 * Return: 1 if true
 */
int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
{
return (1);
}
return (0);
}

/**
 * _isalpha - checks for alphabetic char
 * @c: The input
 * Return: 1 if c is alphabetic
 */

int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
 * _atoi - converts a string to an int
 * @s: string
 * Return: 0 if no numbers in string
 */

int _atoi(char *s)
{
int i, sign = 1, flag = 0, out;
unsigned int result = 0;
for (i = 0; s[i] != '\0' && flag != 2; i++)
{
if (s[i] == '-')
sign *= -1;

if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result *= 10;
result += (s[i] - '0');
}
else if (flag == 1)
flag = 2;
}

if (sign == -1)
out = -result;
else
out = result;
return (out);
}
