#include "shell.h"
#include <unistd.h>
#include <string.h>
/**
 * print_env - prints environment
 * @env: environment
 * Return: nth
 */
void print_env(char **env)
{
	int j = 0;

	for (j = 0; env[j] != NULL; j++)
	{
		write(STDOUT_FILENO, env[j], _strlen(env[j]));
		write(STDOUT_FILENO, "\n", 1);
	}
}

