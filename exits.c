#include "shell.h"
/**
*_strncpy - the function copies a string
*@dest: it is the destination string to be copied to
*@src: this is the source string
*@n: it's the amount of characters to be copied
*Return: the concatenated string
*/
char *_strncpy(char *dest, char *src, int n)
{
int a, b;
char *t = dest;
a = 0;
while (src[a] != '\0' && a < n - 1)
{
dest[a] = src[a];
a++;
}
if (a < n)
{
b = a;
while (b < n)
{
dest[b] = '\0';
b++;
}
}
return (t);
}
/**
*_strncat - the function concatenates two strings
*@dest: this is the first string
*@src: it is the second string
*@n: amount of bytes to be maximally used
*Return: the concatenated string
*/
char *_strncat(char *dest, char *src, int n)
{
int a, b;
char *t = dest;
a = 0;
b = 0;
while (dest[a] != '\0')
a++;
while (src[b] != '\0' && b < n)
{
dest[a] = src[b];
a++;
b++;
}
if (b < n)
dest[a] = '\0';
return (t);
}
/**
**_strchr - the function locates a char in a string
*@t: string to be parsed
*@c: this is the character to look for
*Return: (t) a pointer to the memory area t
*/
char *_strchr(char *t, char c)
{
do {
if (*t == c)
return (t);
} while (*t++ != '\0');
return (NULL);
}
