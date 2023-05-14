#include "shell.h"
/**
*       _strlen -The function returns the length of a string
*       @c: This is the string whose length is checked
*
*       Return: the integer length of string
*/
int _strlen(char *c)
{
int j = 0;
if (!c)
return (0);
while (*c++)
j++;
return (j);
}
/**
*       _strcmp -the function performs lexicogarphic comparison of two strings.
*       @c1: it is the first string
*       @c2: the second string
*
*       Return: negative if c1 < c2, positive if c1 > c2, zero if c1 == c2
*/
int _strcmp(char *c1, char *c2)
{
while (*c1 && *c2)
{
if (*c1 != *c2)
return (*c1 - *c2);
c1++;
c2++;
}
if (*c1 == *c2)
return (0);
else
return (*c1 < *c2 ? -1 : 1);
}
/**
*       starts_with - the function checks if needle starts with haystack
*       @haystack: this is the string to search
*       @needle: the substring to find
*
*       Return: the address of next char of haystack or NULL
*/
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}
/**
*       _strcat - the function concatenates two strings
*       @dest: this is the destination buffer
*       @src: it is the source buffer
*
*       Return: the pointer to destination buffer
*/
char *_strcat(char *dest, char *src)
{
char *ret = dest;
while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}
