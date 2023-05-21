#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @s: pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the number of bytes to be filled
 * Return: pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
    for (unsigned int i = 0; i < n; i++) {
        s[i] = b;
    }
    return s;
}

/**
 * ffree - frees a string of strings
 * @pp: pointer to a string of strings
 */
void ffree(char **pp)
{
    if (!pp) {
        return;
    }
    for (int i = 0; pp[i]; i++) {
        free(pp[i]);
    }
    free(pp);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to the reallocated block of memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *p;

    if (!ptr) {
        return malloc(new_size);
    }
    if (!new_size) {
        free(ptr);
        return NULL;
    }
    if (new_size == old_size) {
        return ptr;
    }

    p = malloc(new_size);
    if (!p) {
        return NULL;
    }

    for (unsigned int i = 0; i < old_size && i < new_size; i++) {
        p[i] = ((char *)ptr)[i];
    }
    free(ptr);
    return p;
}
