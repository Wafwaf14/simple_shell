#include "main.h"

/**
* built_picker - returning the builtin command
* @line: stdin input
* @delimiter: character to split line with
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
* @line: line with builtin inputted
*
* Return: 0 if successful or -1 if it fails
*/

int handle_builtin(char *line)
{
const char *builtin = (const char *)built_picker(line, " ");

if (_strcmp(builtin, "env") == 0)
{
	envir();
	free((char *)builtin);
	return (0);
}
else if (_strcmp(builtin, "exit") == 0)
{
	exit_status(line);
	free((char *)builtin);
	return (0);
}
else if (_strcmp(builtin, "cd") == 0)
{
	_cd(line);
	free((char *)builtin);
	return (0);
}

free((char *)builtin);
return (-1);
}

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
int i, d, n, len, f, digit;

i = 0;
d = 0;
n = 0;
len = 0;
f = 0;
digit = 0;

while (s[len] != '\0')
	len++;

while (i < len && f == 0)
{
	if (s[i] == '-')
		++d;

	if (s[i] >= '0' && s[i] <= '9')
	{
		digit = s[i] - '0';
		if (d % 2)
			digit = -digit;
		n = n * 10 + digit;
		f = 1;
		if (s[i + 1] < '0' || s[i + 1] > '9')
			break;
		f = 0;
	}
	i++;
}

if (f == 0)
	return (0);

return (n);
}

/**
* _getenv - gets the value of the environment variable
* @env_var: environment variable to value of
*
* Return: value of environment variable
*/

char *_getenv(const char *env_var)
{
	int i = 0;
	char **tab, *var, *val, *result;

	while (environ[i])
	{
		tab = strtow(environ[i], "=");
		val = tab[1];
		var = tab[0];
		if (_strcmp(env_var, var) == 0)
		{
			free(var);
			free(tab);
			result = malloc(_strlen(val) + 1);
			if (result == NULL)
				return (NULL);
			_strcpy(result, val);
			free(val);
			return (result);
		}
		free(var), free(val), free(tab);
		i++;
	}
	return (NULL);
}

/**
* hash_filter - removing comments
* @line: pointer to line with hash comment
*
* Return: pointer to unhashed line or NULL on failure
* or line if hash is not present
*/

char *hash_filter(char *line)
{
char *unhashed, *hash = "#", *space = " ";
int flag, count, i;

i = count = flag = 0;
while (line[i] == *space)
	i++;

count = i;
while (line[i])
{
	if (line[i] == *hash)
	{
		flag = 1;
		break;
	}
	i++;
}

if (flag == 1)
{
	unhashed = malloc(sizeof(char) * (i - 1));
	if (unhashed == NULL)
		return (NULL);

	if (count == i)
		return (NULL);
	while (count < i)
	{
		unhashed[count] = line[count];
		count++;
	}
}
else
{
	return (line);
}

return (unhashed);
}
