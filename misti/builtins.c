#include "main.h"

/**
* envir - printing the current environment
*
* Return: void
*/

void envir(void)
{
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

void _cd(char *line)
{
char **tab, *old_var = "OLDPWD";
char *cur_cwd, *cwd = getcwd(NULL, 0);
char *prev_cwd = _getenv("OLDPWD");
int result;
char *env_var = "PWD", *home = _getenv("HOME");

if ((setenv(old_var, cwd, 1)) == -1)
	perror("setenv");
tab = strtow(line, " ");

if (tab[1] != NULL)
{
	if ((_strcmp(tab[1], "-")) == 0)
	{
		result = chdir((const char *)prev_cwd);
		if (result == -1)
			perror("cd");
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
	result = chdir((const char *)home);
	if (result == -1)
		perror("cd");
}

cur_cwd = getcwd(NULL, 0);
if ((setenv(env_var, cur_cwd, 1)) == -1)
	perror("setenv");

free(tab);
free(cur_cwd);
free(cwd);
}

/**
* handle_alias - grouping aliases
* @line: pointer to line from stdin
* @pwd: pointer to working directory with the bash_alias file
*
* Return: suitable integer
*/

int handle_alias(char *line, char *pwd)
{
char **tabs;

if (line == NULL)
	return (0);

tabs = strtow(line, " ");

if ((_strcmp((const char *)tabs[0], "alias")) == 0)
{
	_alias(tabs, pwd);
	return (1);
}

return (0);
}
