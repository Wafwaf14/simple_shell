#include "main.h"

/**
* exec - executing a command
* @line: pointer to line with command
*
* Return: void
*/

int exec(char *line)
{
int word_num, j;
char **argv, *commando;

word_num = count_words(line, " ");
argv = malloc((word_num + 1) * sizeof(char *));
if (argv == NULL)
	return (-1);
argv = strtow(line, " ");
commando = find_path(argv[0]);
if (commando == NULL)
{
	for (j = 0; j <= word_num; j++)
		free(argv[j]);
	free(argv);
	perror("/shell");
	return (-1); }
else
	argv[0] = commando, child_pr(argv);

for (j = 0; j < word_num; j++)
	free(argv[j]);
free(argv);
return (0);
}
