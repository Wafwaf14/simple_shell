#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/stat.h>

/**** STRING HANDLING FUNCTIONS ******/
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int count_words(char *str, const char *delimiter);
char *copy_word(char *str, int start, int end);
char **strtow(char *str, const char *delimiter);

/***** HANDLING THE PATH *****/
char *find_path(char *command);

#endif
