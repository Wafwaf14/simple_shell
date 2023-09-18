#include "main.h"

/**
* _strcpy_const - copy string src onto string dest
* @dest: destination to copy string
* @src: source of string
*
* Return: the pointer to dest
*/

char *_strcpy_const(char *dest, const char *src)
{
int n;
int i;
n = 0;

while (src[n] != '\0')
{
	n++;
}

for (i = 0 ; i < n ; i++)
{
	dest[i] = src[i];
}

for (; i == n ; i++)
{
	dest[i] = '\0';
}

return (dest);
}
