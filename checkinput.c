#include <stdlib.h>
#include "shell.h"
#include <stdio.h>
#include <string.h>
/**
* checkinput - checks for input in an array
* @str: string
* Return: int
*/
int checkinput(char *str)
{
	char *buffer = NULL;
	size_t n = 0;
	ssize_t j;

	j = getline(&buffer, &n, stdin);
	if (j == -1)
	{
		free(buffer);
		return (1);
	}
	buffer = strtok(buffer, "\n");
	if (buffer[0] != '\0')
	{
		_strcpy(str, buffer);
		free(buffer);
		return (0);
	}
	else
	{
		free(buffer);
		return (1);
	}
}
/**
* _strcpy - copies a str
* @src: source
* @dest: destination
* Return: dest
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
