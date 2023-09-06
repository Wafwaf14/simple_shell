#include "main.h"

int main(int argc, char **argv) {
int i;
int j;
struct stat st;
char *file;
char *path;
char **tab;
char *dir;
char *full_path;

for (i = 1; i < argc; i++)
{
	file = argv[i];
	path = getenv("PATH");
	tab = strtow(path, ":");
	if (tab == NULL)
	{
		return (-1);
	}

	for (j = 0; tab[j] != NULL; j++)
	{
		dir = tab[j];
		full_path = malloc(_strlen(dir) + _strlen(file) + 2);
		_strcpy(full_path, dir);
		_strcat(full_path, "/");
		_strcat(full_path, file);

		if (stat(full_path, &st) == 0)
		{
			if (st.st_mode & S_IXUSR)
			{
				printf("%s\n", full_path);
			}
		}

		free(full_path);
	}

	free(tab);
}

return (0);
}

