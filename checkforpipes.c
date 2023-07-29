#include <stdio.h>
#include "shell.h"

/**
 * checkforpipes - checks for pipes
 * @str: pointer to a string
 * @args: pointer to arguments
 * @args_pipes: pointer to pipe arguments
 * @env: points to the environment variable
 * Return: int
 */

int checkforpipes(char *str, char **args, char **args_pipes, char **env)
{
	char *pipes[2];
	int i = 0;

	i = pipechecker(str, pipes);
	if (i == 1)
	{
		parsecmds(pipes[0], args);
		parsecmds(pipes[1], args_pipes);
	}
	else
		parsecmds(str, args);
	if (mycmds(args, env))
		return (0);
	else
		return (1 + i);
}

