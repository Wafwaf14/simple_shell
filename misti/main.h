#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/stat.h>

/****** MAIN OPERATIONS **********/
void child_pr(char **argv);

/**** STRING HANDLING FUNCTIONS ******/
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int count_words(char *str, const char *delimiter);
char *copy_word(char *str, int start, int end);
char **strtow(char *str, const char *delimiter);
int _strcmp(const char *str1, const char *str2);
int _strlen_const(const char *s);

/***** HANDLING THE PATH *****/
char *find_path(char *command);

/**** BUILTIN COMMANDS *****/
void envir(void);
int handle_builtin(char *line);
char *built_picker(char *line, const char *delimiter);

#endif
