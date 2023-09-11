#include "main.h"

/**
* main - Simple shell 0.4
*
* Return: 0
*/

int main(void)
{
char *line;
size_t len;
ssize_t nread;
int result;

len = 0;
while (true)
{
	printf("$ ");
	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		printf("\n");
		break;
	}
	line[nread - 1] = '\0';
	if (nread < 0)
		break;
	result = handle_builtin(line);
	if (result == 0)
		continue;
	else
		break;
}
return (0);
}
