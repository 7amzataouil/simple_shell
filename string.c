#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	if (!s)
		return 0;

	int len = 0;
	
	for (len = 0; s[len]; len++)
		continue;

	return len;
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2)) {
		s1++;
		s2++;
    }

    return (*s1 - *s2);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle) {
		if (*needle != *haystack) {
			return NULL;
        }
		haystack++;
		needle++;
    }

	return (char *)haystack;
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest) {
		dest++;
    }

	while (*src) {
		*dest++ = *src++;
    }

	*dest = '\0';
	return ret;
}

