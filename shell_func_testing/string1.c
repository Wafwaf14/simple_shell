#include "main.h"

/**
* _strcpy - copy string src onto string dest
* @dest: destination to copy string
* @src: source of string
*
* Return: the pointer to dest
*/

char *_strcpy(char *dest, char *src)
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

/**
* _strcat - concentating on string onto another
* @dest: destination file
* @src: source file
*
* Return: pointer to dest
*/

char *_strcat(char *dest, char *src)
{
int len, leng, i, p, sum;
len = 0;
leng = 0;
p = 0;

while (dest[len] != '\0')
	len++;

while (src[leng] != '\0')
	leng++;

i = len;
sum = len + leng;

while (i < sum && p < leng)
{
	dest[i] = src[p];
	i++;
	p++;
}

dest[i] = '\0';

return (dest);
}

/**
* _strlen - printing the length of a string
* @s: string being dereferenced
*
* Return: 0 if successful
*/

int _strlen(char *s)
{
int i;
for (i = 0 ; *s != '\0' ; i++)
{
	s++;
}

return (i);
}
