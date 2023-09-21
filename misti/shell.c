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
char *line = NULL, *unhashed;
size_t len = 0;
ssize_t nread;
char *pwd1 = _getenv("PWD");

if (av[1] == NULL)
{
	while (true)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1 || line == NULL)
		{
			if (errno == EAGAIN || errno == EWOULDBLOCK)
				break;
			printf("\n");
			break; }
		line[nread - 1] = '\0';
		if (nread < 0)
			continue;
		if ((handle_empty_string(line)) == -1)
			continue;
		unhashed = hash_filter(line);
		if (unhashed == NULL)
			continue;
		if (handle_builtin(unhashed) == 0)
		{
			free(unhashed);
			continue; }
		else
			exec(unhashed); }

}
else
	handle_file(av[1]);
free(unhashed);
delete_file(pwd1);
free(pwd1);
return (0);
}
