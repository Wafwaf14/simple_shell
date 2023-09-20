#include "main.h"

/**
* find_path - expanding the shell command to the
* executable that handles it
* @command: command to expand
*
* Return: pointer to the full_path
*/

char *find_path(char *command)
{
int j;
struct stat st;
char *file, *path, **tab, *dir, *full_path;

file = command;
path = getenv("PATH");
tab = strtow(path, ":");
if (tab == NULL)
{
	return (NULL);
}
if (command[0] != '/')
{
	for (j = 0; tab[j] != NULL; j++)
	{
		dir = tab[j];
		full_path = malloc(_strlen(dir) + _strlen(file) + 2);
		_strcpy(full_path, dir), _strcat(full_path, "/"), _strcat(full_path, file);

		if (stat(full_path, &st) == 0)
		{
			if (st.st_mode & S_IXUSR)
				return (full_path);
		}
		free(full_path);
	}
	free(tab);
}
else
{
	full_path = command;
	if (stat(full_path, &st) == 0)
	{
		if (st.st_mode & S_IXUSR)
			return (full_path);
	}
	free(full_path);
}

return (NULL);
}
