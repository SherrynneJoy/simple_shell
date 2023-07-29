#include <stdio.h>
#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
/**
 * getpath - gets a path in an environment
 * @command: cmd input
 * Return: path
 */
char *getpath(char *command)
{
	char *path, *pathcp, *tokens, *filepath = NULL;
	struct stat st;
	int cmd_len = 0, dir_len = 0;

	path = _getenv("PATH");
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
/**
 * _getenv - gets environment of a path
 * @name: name being searched for
 * Return: path
 */
char *_getenv(char *name)
{
	int len, i = 0;
	extern char **environ;

	if (name == NULL || environ == NULL)
		return (NULL);
	len = strlen(name);
	for (i = 0; environ != NULL; i++)
	{
		if (strncmp(name, environ[i], len) == 0 && environ[i][len] == '=')
			return (environ[i] + len + 1);
	}
	return (NULL);
}
/**
 * _strdup - duplicates a str
 * @src: source
 * Return: duplicated string
 */
char *_strdup(const char *src)
{
	size_t len;
	char *dup;

	if (src == NULL)
		return (NULL);
	len = strlen(src);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	strcpy(dup, src);
	return (dup);
}
/**
 * _strcat - concatenates 2 strings
 * @dest: destination
 * @src: source
 * Return: concatenated str
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
