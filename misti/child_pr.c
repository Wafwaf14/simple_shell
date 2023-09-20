#include "main.h"

/**
* child_pr - creates a child process to run the shell command
* @argv: pointer to and array of pointers to strings
* @len: number of elements in argv
*
* Return: void
*/

void child_pr(char **argv)
{
pid_t child;
int status;

child = fork();
if (child == -1)
{
	perror("./shell");
	exit(0);
}
if (child == 0)
{
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("./shell");
		exit(0);
	}
}
else
	wait(&status);
}
