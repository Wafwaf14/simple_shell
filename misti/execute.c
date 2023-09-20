#include "main.h"

/**
* exec - executing a command
* @line: pointer to line with command
*
* Return: void
*/

void exec(char *line)
{
size_t word_num;
char **argv, *command;

word_num = count_words(line, " ");
argv = malloc((word_num + 1) * sizeof(char *));
argv = strtow(line, " ");
command = find_path(argv[0]);
if (command == NULL)
	perror("/shell");
else
	argv[0] = command, child_pr(argv);
}
