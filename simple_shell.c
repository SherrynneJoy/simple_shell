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
	int interactive_mode = isatty(STDIN_FILENO), i, m_read;

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
		while ((m_read = read(STDIN_FILENO, str, sizeof(str) - 1)) > 0)
		{
			str[m_read] = '\0';
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

