#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * mycmds - holds default cmds
 * @args: pointer to str
 * @env: environment variable
 * Return: cmds if found
 */
char *mycmds(char **args, char **env)
{
	char *cmds[] = {"exit", "env"};
	int i = 0, count = 0;

	while (i < 2)
	{
		if (_strcmp(args[0], cmds[i]) == 0)
		{
			count = i + 1;
			break;
		}
		i++;
	}
	switch (count)
	{
		case 1:
			exit(EXIT_SUCCESS);
			break;
		case 2:
			print_env(env);
			break;
		default:
			break;
	}
	return (0);
}
