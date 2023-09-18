#include "main.h"

/**
* _strcpy_const - copy string src onto string dest
* @dest: destination to copy string
* @src: source of string
*
* Return: the pointer to dest
*/

char *_strcpy_const(char *dest, const char *src)
{
int n;
int i;
n = 0;

while (src[n] != '\0')
{
	n++;
}

for (i = 0 ; i < n ; i++)
{
	dest[i] = src[i];
}

for (; i == n ; i++)
{
	dest[i] = '\0';
}

return (dest);
}

/**
* check_alias_name - check the alias with that particular name
* @bash_alias: pointer to file
* @strin: name of alias to check
*
* Return: integer
*/

int check_alias_name(const char *bash_alias, char *strin, char *value, char *pwd)
{
int fd, fc, i, nread, flag = 0;
char *string, **split, *string2, **split2;
struct stat file_info;

fd = open(bash_alias, O_RDONLY);
if (fd == -1)
{
	perror("open");
	return (1);
}
if (fstat(fd, &file_info) < 0)
{
	close(fd);
	perror("fstat");
}
string = malloc(file_info.st_size + 1);
if (string == NULL)
{
	close(fd);
	perror("malloc");
}
nread = read(fd, string, file_info.st_size);
if (nread == -1)
	perror("read");
fc = close(fd);
if (fc == -1)
	perror("close");

split = strtow(string, "\n");
if (split == NULL)
	return (2);

i = 0;
while (split[i] != NULL)
{
	string2 = split[i];
	split2 = strtow(string2, "=");
	if ((_strcmp((const char *)split2[0], (const char *)strin)) == 0)
	{
		flag = 1;
		change_alias_value(bash_alias, string, strin, value, pwd);
		break;
	}
	i++;
}
if (flag == 0)
{
	return (1);
}

return (0);
}

/**
* change_alias_name - change the alias with that particular name
* @bash_alias: pointer to file
* @str: string with contents of bash_alias
* @name: name of alias to check
* @value: value of alias to check
*
* Return: integer
*/

void change_alias_value(const char *bash_alias, char *str, char *name, char *value, char *pwd)
{
int fd, i, nwrite;
char **split, *str2, **split2;
char *equal = "=", *newline = "\n";
char *temp = pwd;
fd = open ("temp", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
if (fd == -1)
	return;

split = strtow(str, "\n");

i = 0;
while (split[i] != NULL)
{
	str2 = split[i];
	split2 = strtow(str2, "=");
	if ((_strcmp((const char *)split2[0], (const char *)name)) == 0)
	{
		nwrite = write(fd, name, _strlen(name));
		nwrite = write(fd, equal, 1);
		nwrite = write(fd, value, _strlen(value));
		nwrite = write(fd, newline, 1);
		if (nwrite == -1)
			return;
	}
	else
	{
		nwrite = write(fd, str2, _strlen(str2));
		nwrite = write(fd, newline, 1);
		if (nwrite == -1)
			return;
	}
	i++;
}

free(str2);
if (close(fd) == -1)
{
	perror("close");
	return;
}
if (remove(bash_alias) != 0)
{
	perror("remove");
	return;
}
if (rename(temp, bash_alias) != 0)
{
        perror("rename");
        return;
}
}

