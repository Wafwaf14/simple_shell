#include "main.h"

/**
* delete_file - deleting bash_alias after main
*
* Return: void
*/

void delete_file(char *pwd)
{
char *bash = "/bash_alias";
const char *bash_alias;
char *temp = malloc(_strlen(pwd) + _strlen(bash) + 1);
if (temp == NULL)
{
	perror("malloc");
	return;
}
_strcpy(temp, pwd);
_strcat(temp, bash);
bash_alias = (const char *)temp;
remove(bash_alias);

free(temp);
}
