#include "shell.h"
/**
*       _memset -the function fills the memory with a constant byte
*       @p: this is the pointer to the memory area
*       @b:this is the byte to fill *p with
*       @n: it is the amount of bytes to be filled
*       Return: (p) a pointer to the memory area p
*/
char *_memset(char *p, char b, unsigned int n)
{
unsigned int j;
for (j = 0; j < n; j++)
p[j] = b;
return (p);
}
/**
*       ffree - the function frees a string of strings
*       @ss: string of strings
*/
void ffree(char **ss)
{
char **a = ss;
if (!ss)
return;
while (*ss)
free(*ss++);
free(a);
}
/**
*       _realloc - a function that reallocates a block of memory
*       @ptr: it is a pointer to previous malloc'ated block
*       @old_size: it's a byte size of previous block
*       @new_size: this is a byte size of new block
*
*       Return: pointer to da ol'block nameen.
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *s;
if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);
s = malloc(new_size);
if (!s)
return (NULL);
old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
s[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (s);
}
