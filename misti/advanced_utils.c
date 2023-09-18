#include "main.h"

/**
* handle_file - handling a file full of commands
* @filen: name of the file to open
*
* Return: 0 or -1
*/

int handle_file(char *filen)
{
int i, fd, fc, nread, word_num;
char *file, **line, **argv, *command, *liner;
struct stat file_info;

fd = open(filen, O_RDONLY);
if (fd == -1)
	return (-1);
if (fstat(fd, &file_info) < 0)
{
	close(fd);
	return (-1);
}
file = malloc(file_info.st_size + 1);
if (file == NULL)
{
	close(fd);
	return (-1);
}
nread = read(fd, file, file_info.st_size);
if (nread == -1)
	return (-1);
fc = close(fd);
if (fc == -1)
	return (-1);
i = 0;
line = strtow(file, "\n");
while (line[i] != NULL)
{
	if ((handle_empty_string(line[i])) == -1)
		continue;
	liner = hash_filter(line[i]);
	if (liner == NULL)
		continue;
	word_num = count_words(liner, " ");
	argv = malloc((word_num + 1) * sizeof(char *));
	argv = strtow(liner, " ");
	command = find_path(argv[0]);
	if (command == NULL)
		continue;
	else
		argv[0] = command, child_pr(argv);
	i++;
}
free(line), free(file), free(argv);
return (0);
}

/**
* print_alias_all - print all elements in an alias list
* @h: pointer to list_t singly linked list
*
* Return: integer
*/

int print_alias_all(const char *bash_alias)
{
int fd, fw, fc;
ssize_t count;
char ch;
count = 0;

fd = open(bash_alias, O_RDONLY);
if (fd == -1)
	return (-1);

while (((read(fd, &ch, 1)) > 0))
{
	fw = write(STDOUT_FILENO, &ch, 1);
	if (fw != 1)
		return (0);
	count++;
}

fc = close(fd);
if (fc == -1)
	return (0);

return (1);
}

/**
* print_alias_name - print the alais with that particular name
* @h: pointer to list_t singly linked list
* @name: name of alias to print
*
* Return: void
*/

void print_alias_name(const char *bash_alias, char *name)
{
int fd, fc, i, nread, flag = 0;
char *string, **split, *string2, **split2;
struct stat file_info;

fd = open(bash_alias, O_RDONLY);
if (fd == -1)
	perror("open");
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

i = 0;
while (split[i] != NULL)
{
	string2 = split[i];
	split2 = strtow(string2, "=");
	if ((_strcmp((const char *)split2[0], (const char *)name)) == 0)
	{
		flag = 1;
		printf("%s\n", string2);
		break;
	}
	i++;
}
if (flag == 0)
	printf("%s: no such alias\n", name);

}

/**
* add_alias - adding alias at the end of a file
* @str: pointer to string to append
*
* Return: suitable integer
*/

int add_alias(char *str, const char *bash_alias)
{
int fd, fw, fc;
size_t len;

fd = open (bash_alias, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
if (fd == -1)
	return (-1);

len = _strlen(str);
str[len] = '\n';
len++;
fw = write(fd, str, len);
if (fw == -1)
	return (-1);
fc = close(fd);
if (fc == -1)
	return (-1);

return (1);
}

/**
* _alias - adding, modifying and printing an alias(es)
* @tab: pointer to pointers of alias
*
* Return: void
*/

void _alias(char **tab)
{
int i;
char *liase;

i = 1;
if (tab[1] == NULL)
	print_alias_all("bash_alias");

else
{
	while (tab[i] != NULL)
	{
		liase = tab[i];
		if ((alias_char_finder(liase)) == 1)
			print_alias_name("bash_alias", liase);
		if ((alias_char_finder(liase)) == 2)
			add_alias(liase, "bash_alias");
		if ((alias_char_finder(liase)) == 0)
			continue;
		i++;
	}
}
}

