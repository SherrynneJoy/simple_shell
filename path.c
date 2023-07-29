#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * _getenv - gets the environment variable
 * @name: the name of the command
 * Return: nothing
 */
char *_getenv(char *name)
{
	int length, i = 0;
	extern char **environ;

	if (name == NULL || environ == NULL)
		return (NULL);
	length = _strlen(name);
	for (i = 0; environ != NULL; i++)
	{
		if (strncmp(name, environ[i], length) == 0 && environ[i][length] == '=')
			return (environ[i] + length + 1);
	}
	return (NULL);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination
 * @src: source
 * Return: concatenated string
 */

char *_strcat(char *dest, char *src)
{
	char *result;
	int i = 0;

	if (dest == NULL || src == NULL)
		return (NULL);
	result = dest;
	while (result[i] != '\0')
		result++;
	while (src[i] != '\0')
	{
		result[i] = src[i];
		result++;
		src++;
	}
	result = '\0';
	return (dest);
}

/**
 * getpath - gets a path from the environment
 * @command: command being searhed for
 * Return: cmd if found
 */
char *getpath(char *command)
{
	char *path, *pathcp, *tokens, *filepath = NULL;
	struct stat st;
	int cmd_len = 0, dir_len = 0;

	path = getenv("PATH");
	if (path)
	{
		pathcp = _strdup(path);
		cmd_len = _strlen(command);
		tokens = strtok(pathcp, ":");
		while (tokens != NULL)
		{
			dir_len = _strlen(tokens);
			filepath = malloc(sizeof(char) * (cmd_len + dir_len + 3));
			if (filepath == NULL)
				return (NULL);
			_strcpy(filepath, tokens);
			_strcat(filepath, "/");
			_strcat(filepath, command);
			_strcat(filepath, "\0");
			if (stat(filepath, &st) == 0)
			{
				free(pathcp);
				return (filepath);
			}
			else
			{
				free(filepath);
				tokens = strtok(NULL, ":");
			}
		}
		free(pathcp);
		if (stat(command, &st) == 0)
			return (command);
		return (NULL);
	}
	return (NULL);
}
