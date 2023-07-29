#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
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

