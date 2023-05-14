#include "shell.h"
/**
*       _strcpy -the function copies a string
*       @dest: it's the destination
*       @src: it's the source
*
*       Return: this is the pointer to destination
*/
char *_strcpy(char *dest, char *src)
{
int j = 0;
if (dest == src || src == 0)
return (dest);
while (src[j])
{
dest[j] = src[j];
j++;
}
dest[j] = 0;
return (dest);
}
/**
*       _strdup -the function that duplicates a string
*       @str: this is the string to duplicate
*
*       Return: the pointer to the duplicated string
*/
char *_strdup(const char *str)
{
int len = 0;
char *ret;
if (str == NULL)
return (NULL);
while (*str++)
len++;
ret = malloc(sizeof(char) * (len + 1));
if (!ret)
return (NULL);
for
(len++;
len--;)
ret[len] = *--str;
return (ret);
}
/**
*       _puts - function that prints an input string
*       @str: it's the string to be printed
*
*       Return: Nothing
*/
void _puts(char *str)
{
int j = 0;
if (!str)
return;
while (str[j] != '\0')
{
_putchar(str[j]);
j++;
}
}
/**
*       _putchar -the function that writes the character c to stdout
*       @c: The character to print
*
*       Return: On success 1.
*       On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
static int j;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)
{
write(1, buf, j);
j = 0;
}
if (c != BUF_FLUSH)
buf[j++] = c;
return (1);
}
