#include "main.h"

/**
* built_picker - returning the builtin command
* @line: stdin input
*
* Return: builtin command
*/

char *built_picker(char *line, const char *delimiter)
{
char *builtin;
int i, j, start, end;

i = j = 0;
while (line[i] == *delimiter)
	i++;
start = i;
while (line[i] != *delimiter && line[i] != '\0')
	i++;
end = i - 1;

builtin = malloc(sizeof(char) * (end - start + 2));
if (line == NULL)
        return (NULL);

j = 0;
for (i = start; i <= end; i++)
{
        builtin[j] = line[i];
        j++;
}
builtin[j] = '\0';
return (builtin);
}


/**
* handle_builtin - handling builtin commands by rerouting
* @builtin: builtin inputted
*
* Return: 0 if successful or -1 if it fails
*/

int handle_builtin(char *line)
{
const char *builtin = (const char *)built_picker(line, " ");

if (_strcmp(builtin, "env") == 0)
{
	envir();
	return (0);
}

return (-1);
}
