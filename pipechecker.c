#include "shell.h"
#include <stdio.h>
#include <string.h>
/**
 * pipechecker - checks for pipes
 * @str: a pointer to chars
 * @pipes: points to a string pointer
 * Return: int
 */

int pipechecker(char *str, char **pipes)
{
	int j = 0;

	pipes[0] = NULL;
	pipes[1] = NULL;
	pipes[j] = strtok(str, "|");
	while (j < 2)
	{
		if (pipes[j] == NULL)
			break;
		pipes[j] = strtok(NULL, "|");
		j++;
	}
	if (pipes[1] == NULL)
		return (0);
	else
		return (1);
}

