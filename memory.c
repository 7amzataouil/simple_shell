#include "shell.h"

/**
 * @ptr: address of the pointer to free
 * bfree - free a pointer and NULL the address
 *
 * Return: 1 if freed, else 0
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
