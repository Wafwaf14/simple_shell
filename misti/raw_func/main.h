#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <string.h>

/**** BUILTIN COMMANDS *****/
void envir(void);
int handle_builtin(char *line);
char *built_picker(char *line, const char *delimiter);

#endif
