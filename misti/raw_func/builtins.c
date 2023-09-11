#include "main.h"

/**
* envir - printing the current environment
*
* Return: void
*/

void envir(void)
{
extern char **environ;
int i = 0;
while (environ[i])
{
	printf("%s\n", environ[i]);
	i++;
}
}
