#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

/****** MAIN OPERATIONS **********/
void child_pr(char **argv);
char *hash_filter(char *line);
int delete_file(char *pwd) __attribute__((destructor));
int exec(char *line);

/**** STRING HANDLING FUNCTIONS ******/
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int count_words(char *str, const char *delimiter);
char *copy_word(char *str, int start, int end);
char **strtow(char *str, const char *delimiter);
int _strcmp(const char *str1, const char *str2);
int _strlen_const(const char *s);
int handle_empty_string(char *line);
char *_strcpy_const(char *dest, const char *src);

/***** HANDLING THE PATH *****/
char *find_path(char *command);

/**** BUILTIN COMMANDS *****/
void envir(void);
int exit_status(char *line);
void _cd(char *line);
int handle_builtin(char *line);
char *built_picker(char *line, const char *delimiter);
int _atoi(char *s);
char *_getenv(const char *env_var);

/******* HANDLING A FILE WITH COMMANDS ********/
int handle_file(char *filen);

/***** HANDLING ALIAS ******/
int handle_alias(char *line, char *pwd);
int _alias(char **tab, char *pwd);
int add_alias(char *str, const char *bash_alias, char *pwd);
void print_alias_name(const char *bash_alias, char *name);
int print_alias_all(const char *bash_alias);
int alias_char_finder(char *lias);
int change_alias_value(const char *bash_alias, char *str,
char *name, char *value, char *pwd);
int check_alias_name(const char *bash_alias,
char *strin, char *value, char *pwd);
int replace_bash(int fd, const char *tempsi,
const char *bash_alias);

#endif
