#include "main.h"

/**
* handle_file - handling a file full of commands
* @filename: name of the file to open
*
* Return: 0 or -1
*/

int handle_file(char __attribute__((unused)) *filen)
{
int i, fd, fc, count, nwrite, nread, word_num;
char *file, **line, **argv, ch, *command;

fd = open(filen, O_RDONLY);
if (fd == -1)
	return (-1);

count = 0;
while ((nread = read(fd, &ch, 1)) > 0)
	count++;

if (nread == -1)
	return (-1);

file = malloc(sizeof(char) * count);
if (file == NULL)
	return (-1);

nread = 0, lseek(fd, 0, SEEK_SET);
while ((nread = read(fd, file, count)) > 0)
{
	nwrite = write(1, file, nread);
	if (nwrite == -1)
		return (-1);
}

if (nread == -1)
        return (-1);

fc = close(fd);
if (fc == -1)
	return (-1);

i = 0;
line = strtow(file, "\n");
while (line[i] != NULL)
{
	word_num = count_words(line[i], " ");
	argv = malloc((word_num + 1) * sizeof(char *));
	argv = strtow(line[i], " ");
	command = find_path(argv[0]);
	if (command == NULL)
		break;
	else
		argv[0] = command, child_pr(argv);
	i++;
}
free(line), free(file), free(argv);
return (0);
}
