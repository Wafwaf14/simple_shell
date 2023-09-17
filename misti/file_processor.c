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
