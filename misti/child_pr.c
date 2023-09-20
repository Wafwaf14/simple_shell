#include "main.h"

/**
* child_pr - creates a child process to run the shell command
* @argv: pointer to and array of pointers to strings
* @word_num: number of elements in argv
* @commando: command to free
*
* Return: void
*/

void child_pr(char **argv, char *commando, int word_num)
{
pid_t child;
int status;
int j;

child = fork();
if (child == -1)
{
	free(commando);
	for (j = 0; j < word_num; j++)
		free(argv[j]);
	perror("./shell");
	exit(0);
}
if (child == 0)
{
	if (execve(argv[0], argv, NULL) == -1)
	{
		free(commando);
		for (j = 0; j < word_num; j++)
			free(argv[j]);
		free(argv);
		perror("./shell");
		exit(0);
	}
}
else
	wait(&status);
}
