#include "shell.h"
#include <string.h>
#include <stdlib.h>

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: int
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/**
 * _strlen -measures length of a string
 * @s: string to be measured
 * Return: length
 */
size_t _strlen(char *s)
{
	unsigned int length = 0, i = 0;

	while (s[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}
/**
 * _strdup - duplicates a string
 * @s: string to be duplicated
 * Return: new string
 */
char *_strdup(const char *s)
{
	char *new_s;
	size_t length;

	if (s == NULL)
		return (NULL);
	length = strlen(s);
	new_s = malloc(sizeof(char) * (length + 1));
	if (new_s == NULL)
		return (NULL);
	strcpy(new_s, s);
	return (new_s);
}

/**
 * _strcpy - copies a string
 * @src: source of string
 * @dest: destination of the string
 * Return: copied string
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strchr - shows the first occurrence of a character
 * @s: a string
 * @ch: an int
 * Return: a specific character
 */
char *_strchr(char *s, int ch)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
