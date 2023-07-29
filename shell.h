#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>

int checkinput(char *str);
char *_strcpy(char *dest, char *src);
int checkforpipes(char *str, char **args, char **args_pipes, char **env);
int pipechecker(char *str, char **pipes);
void parsecmds(char *str, char **args);
char *mycmds(char **args, char **env);
void execfn(char **args, char **argv, char **env);
char *getpath(char *command);
void print_env(char **env);
char *_getenv(char *name);
size_t _strlen(char *s);
char *_strdup(const char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, int ch);

#endif
