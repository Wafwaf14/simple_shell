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

int print_alias_all(char *bash_alias)
{
int fd, fw, fc, flag;
ssize_t count;
char ch, *newline = "\n";
count = flag = 0;

fd = open(bash_alias, O_RDONLY);
if (fd == -1)
	return (-1);

while (((read(fd, &ch, 1)) > 0))
{
	fw = write(STDOUT_FILENO, &ch, 1);
	if (fw != 1)
		return (0);
	if (ch == '\'' && flag == 0)
	{
		flag = 1;
		continue;
	}
	if (ch == '\'' && flag == 1)
	{
		flag = 0;
		write(STDOUT_FILENO, newline, 1);
	}
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

void print_alias_name(const list_t *h, char *name)
{
const list_t *current;
char *string;
char **split;

if (h == NULL)
	return;

current = h;
while (current != NULL)
{
	string = current->str;
	split = strtow(string, "=");
	if ((_strcmp((const char *)split[0], (const char *)name)) == 0)
	{
		printf("%s\n", current->str);
		return;
	}
	current = current->next;
}

perror("alias");
}

/**
* add_alias - adding alias at the end of a file
* @str: pointer to string to append
*
* Return: suitable integer
*/

int add_alias(char *str, char *bash_alias)
{
int fd, fw, fc;
size_t len;

fd = open(bash_alias, O_WRONLY | O_APPEND | O_CREAT, 0666);
if (fd == -1)
	return (-1);

len = _strlen(str);
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
char *bash_alias = "bash_alias", *liase;

i = 1;
if (tab[1] == NULL)
	print_alias_all(bash_alias);

else
{
	while (tab[i] != NULL)
	{
		liase = tab[i];
		add_alias(liase, bash_alias);
		i++;
	}
}
}

