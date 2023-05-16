#include "shell.h"
/**
* _eputs - the function prints an input string
* @str: this is the string to be printed
*
* Return: void
*/
void _eputs(char *str)
{
int j = 0;
if (!str)
return;
while (str[j] != '\0')
{
_eputchar(str[j]);
j++;
}
}
/**
* _eputchar - function writes the character c to stderr
* @s: it is the character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _eputchar(char s)
{
static int j;
static char buf[WRITE_BUF_SIZE];
if (s == BUF_FLUSH || j >= WRITE_BUF_SIZE)
{
write(2, buf, j);
j = 0;
}
if (s != BUF_FLUSH)
buf[j++] = s;
return (1);
}
/**
* _putfd - function writes the character s to given df
* @s: this is the character to print
* @df: it is the filedescriptor to write to
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putfd(char s, int df)
{
static int j;
static char buf[WRITE_BUF_SIZE];
if (s == BUF_FLUSH || j >= WRITE_BUF_SIZE)
{
write(df, buf, j);
j = 0;
}
if (s != BUF_FLUSH)
buf[j++] = s;
return (1);
}
/**
* _putsfd - function prints an input string
* @str: this is the string to be printed
* @df: it's the filedescriptor to write to
*
* Return: the number of characters put
*/
int _putsfd(char *str, int df)
{
int j = 0;
if (!str)
return (0);
while (*str)
{
j += _putfd(*str++, df);
}
return (j);
}
