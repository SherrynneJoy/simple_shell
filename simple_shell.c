#include <stdio.h>
#include <string.h>
#include "shell.h"
#include <unistd.h>
/**
 * main - main entry
 * @argc: argument count
 * @av: argument vector
 * @env: NULL terminated array of strings
 * Return: 0
 */
int main(int argc, char **av, char **env)
{
	char str[1024];
	char *args[100], *args_pipes[100], *temp, *newline;
	int interactive_mode = isatty(STDIN_FILENO), i, rd;

	(void)argc;
	if (interactive_mode)
	{
		while (1)
		{
			write(STDOUT_FILENO, "$ ", 2);
			if (checkinput(str) == 1)
				continue;
			i = checkforpipes(str, args, args_pipes, env);
			if (i == 1)
				execfn(args, av, env);
			else if (i == 2)
				continue;
		}
	}
	else
	{
		temp = str;
		while ((rd = read(STDIN_FILENO, str, sizeof(str) - 1)) > 0)
		{
			str[rd] = '\0';
			newline = _strchr(temp, '\n');
			while (newline != NULL)
			{
				*newline = '\0';
				i = checkforpipes(temp, args, args_pipes, env);
				if (i == 1)
					execfn(args, av, env);
				temp = newline + 1;
				newline = _strchr(temp, '\n');
			}
		}
	}
	return (0);
}
/**
 * _strchr - returns first sighting of a specified char
 * @s: string being assessed
 * @ch: variable for the special char
 * Return: specified character
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
