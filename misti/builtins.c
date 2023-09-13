#include "main.h"

/**
* envir - printing the current environment
*
* Return: void
*/

void envir(void)
{
extern char **environ;
int i = 0;
while (environ[i])
{
	printf("%s\n", environ[i]);
	i++;
}
}

/**
* exit_status - exiting the terminal with a given status value
* @line: pointer to line with exit builtin and exit code
*
* Return: void
*/

void exit_status(char *line)
{
char **tab;
int exit_code;

tab = strtow(line, " ");

if (tab[1] != NULL)
{
	exit_code = _atoi(tab[1]);
	exit(exit_code);
}
else
{
	exit(1);
}
}

/**
* _cd - change directory
* @line: line with cd command
*
* Return: void
*/

void _cd(char * line)
{
char **tab;
char *cwd = getcwd(NULL, 0);
int result;

tab = strtow(line, " ");

if (tab[1] != NULL)
{
	if ((_strcmp(tab[1], "-")) == 0)
	{

	}
	else
	{
		result = chdir((const char *)tab[1]);
		if (result == -1)
			perror("cd");
	}
}
else
{

}


free(tab);
free(cwd);
}
