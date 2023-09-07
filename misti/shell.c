#include "main.h"

/**
* main - Simple shell 0.4
*
* Return: 0
*/

int main(void)
{
char *line, *exit_it = "exit", *command, **argv;
size_t len, word_num;
ssize_t nread;

len = word_num = 0;
while (true)
{
	printf("$ ");
	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		printf("\n");
		break;
	}
	line[nread - 1] = '\0';
	if (nread < 0 || *line == *exit_it)
		break;
	word_num = count_words(line, " ");
	argv = malloc((word_num + 1) * sizeof(char *));
	argv = strtow(line, " ");
	command = find_path(argv[0]);
	if (command == NULL)
		perror("/shell");
	else
		argv[0] = command, child_pr(argv);
}
return (0);
}
