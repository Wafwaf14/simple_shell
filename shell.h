#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR	        1
#define CMD_AND	        2
#define CMD_CHAIN       3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE	0
#define USE_STRTOK	0

#define HIST_FILE	".simple_shell_hist"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct list_s - a singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct list_s
{
	int num;
	char *str;
	struct list_s *next;
} list_t;

/**
 * struct pass_info - contains pseudo-arguments to pass into a function,
 * allowing uniform prototype for function pointer struct
 * @arg: a string generated from getline containing arguments
 * @argv: an array of strings generated from arg
 * @path a string path for the current command
 * @argc: the argument count
 * @line_count: the error count
 * @err_num: the error code for exiting
 * @linecout_flag: if on count this line of input
 * @fname: the program filename
 * @env: linked list local copy of environ variable
 * @environ: custom modified copy of environ from env
 * @history: the history node
 * @alias: the alias node
 * @env_changed: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the fd from which to read line input
 * @histcount: the history line number count
 */
typedef struct pass_info /* Ensures that memory leaks are avoided */
{
	char *arg;
	char **argv;
	char *path; /* contains the main arg passed to execve */
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory management */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct built_in - contains a builtin string and related function
 * type: the builtin command flag
 * @func: the function to execute
 */
typedef struct built_in
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* FUNCTIONS IN LOOP_SHELL.C */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* FUNCTIONS IN PARSE.C */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* FUNCTIONS IN ERRORS2.C */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* FUNCTIONS IN STRING2.C */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
int count_words(char *str, const char *delimiter);

/* FUNCTIONS IN STRING1.C */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* FUNCTIONS IN EXIT.C */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* FUNCTIONS IN TOKENIZATION.C */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* FUNCTIONS IN _REALLOC.C */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* FUNCTION IN MEM.C */
int bfree(void **);

/* FUNCTIONS IN ATOI.C */
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* FUNCTIONS IN ERRORS1.C */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* FUNCTIONS IN BUILTIN2.C */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* FUNCTION IN BUILTIN1.C */
int _myhistory(info_t *);
int _myalias(info_t *);

/* FUNCTIONS IN GETLINE.C */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* FUNCTIONS IN GETINFOS.C */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* FUNCTIONS IN ENVIRONMENT.C */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* FUNCTIONS IN GETENVIRON.C */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* FUNCTIONS IN SHELL_HISTORY.C */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/* FUNCTIONS IN LISTS2.C */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* FUNCTIONS IN LISTS1.C */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* FUNCTIONS IN VARIABLES.C */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif
