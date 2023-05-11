#include "shell.h"

/**
 * bfree - A function that frees a pointer and NULLS the address
 * @pointer: This is the address of pointer to free
 * Return: 1 (freed), 0 (otherwise)
 */
int bfree(void **pointer)
{
	if (pointer && *pointer)
	{
		free(*pointer);
		*pointer = NULL;
		return (1);
	}
	return (0);
}
