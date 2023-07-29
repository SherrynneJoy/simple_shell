#include "shell.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
/**
 * execfn - executes commands
 * @args: pointer to arguments
 * @argv: argument vector
 * @env: environment variable
 * Return:0 when successful
 */
void execfn(char **args, char **argv, char **env)
{
	pid_t child_pid;
	char *command = NULL, *newcmd;

	command = args[0];
	newcmd = getpath(command);
	if (newcmd != NULL)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror(argv[0]);
			return;
		}
		if (child_pid == 0)
		{
			if (execve(newcmd, args, env) == -1)
			{
				perror(argv[0]);
				exit(2);
			}
		}
		else
		{
			int status;

			wait(&status);
			if (_strcmp(args[0], newcmd) != 0)
				free(newcmd);
			return;
		}
	}
	else
		perror(argv[0]);
	free(newcmd);
}
