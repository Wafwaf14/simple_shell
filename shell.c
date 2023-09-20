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
char *line;
size_t len = 0;
ssize_t nread;
char *pwd, *pwd1 = _getenv("PWD");

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
			break;
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
		if (handle_alias(line, pwd1) == 1)
			continue;
		else
			exec(line);

	}

}
else
	handle_file(av[1]);
delete_file(pwd1);
return (0);
}
