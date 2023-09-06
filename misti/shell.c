#include "main.h"

/**
* main - creating a simple shell 0.1
*
* Return: 0
*
* Description: This program simply handles EOF and absolute
* file paths
*/

int main(void)
{
pid_t child;
char *line, *exit_it = "exit";
size_t len = 0;
ssize_t nread;
int status;
char **argv = malloc(2 * sizeof(char *));

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
	line = find_path(line);
	argv[0] = malloc(_strlen(line) + 1);
	_strcpy(argv[0], line);
	argv[1] = NULL;
	child = fork();
	if (child == -1)
	{
		perror("./shell");
		return (1);
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
return (0);
}
