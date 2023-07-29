#include "shell.h"
#include <string.h>
#include <stdio.h>
/**
 * parsecmds - handles cmds
 * @str: string being passed
 * @args: pointer to strings
 */
void parsecmds(char *str, char **args)
{
	int j = 0;

	args[j] = strtok(str, " ");
	while (args[j] != NULL)
	{
		j++;
		args[j] = strtok(NULL, " ");
	}
}
