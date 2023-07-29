#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>

int checkforpipes(char *str, char **args, char **args_pipes, char **env);
int checkinput(char *str);
void print_env(char **env);
void execfn(char **args, char **argv, char **env);
char *mycmds(char **args, char **env);
void parsecmds(char *str, char **args);
char *getpath(char *command);
int pipechecker(char *str, char **pipes);
size_t _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(const char *s);
char *_strcat(char *dest, char *src);
char *_getenv(char *name);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, int ch);
#endif

