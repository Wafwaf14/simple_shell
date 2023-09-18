#include "main.h"

/**
* main - Simple shell 1.0
* @ac: argument counter
* @av: argument vector
*
* Return: 0
*
* Description: Handles exit, cd, comments
*/

int main(int __attribute__((unused)) ac, char __attribute__((unused)) **av)
{
char *line, *command, **argv;
size_t len, word_num;
ssize_t nread;
char *pwd;

len = word_num = 0;
if (av[1] == NULL)
{
	while (true)
	{
		pwd = _getenv("PWD");
		printf("misti+wafwaf@ubuntu:~%s$ ", pwd);
		nread = getline(&line, &len, stdin);
		if (nread == -1 || line == NULL)
		{
			printf("\n");
			continue;
		}
		line[nread - 1] = '\0';
		if (nread < 0)
			continue;
		if ((handle_empty_string(line)) == -1)
			continue;
		line = hash_filter(line);
		if (line == NULL)
			continue;
		if (handle_builtin(line) == 0)
			continue;
		if (handle_alias(line) == 1)
			continue;
		else
		{
			word_num = count_words(line, " ");
			argv = malloc((word_num + 1) * sizeof(char *));
			argv = strtow(line, " ");
			command = find_path(argv[0]);
			if (command == NULL)
				perror("/shell");
			else
				argv[0] = command, child_pr(argv);
		}

	}

}
else
	handle_file(av[1]);

return (0);
}
