#include <string.h>
#include "shell.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
/**
* execfn - executes a function
* @args: pointer to string
* @argv: argument vector
* @env: environment variable
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
/**
* _strcmp - comapres 2 strings
* @s1: string 1
* @s2: str 2
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
