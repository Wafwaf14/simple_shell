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

/**
* handle_empty_string - checking if a string is empty
* @line: pointer to string under investigation
*
* Return: 0 if valid string and -1 if empty string
*/

int handle_empty_string(char *line)
{
int i = 0;
char *space = " ";

while (line[i])
{
	if (line[i] != *space)
		return (0);
	i++;
}

return (-1);
}

/**
* alias_char_finder - finding characters that determine
* alias operation to perform
* @lias: pointer to probable alias name and value
*
* Return: numerical values
*/

int alias_char_finder(char *lias)
{
int i = 0, flag = 0;
char *apostro = "'", *space = " ";
char *liase = NULL, **tab;

tab = strtow(lias, "=");
if (tab == NULL)
	return (0);

if (tab[0] == NULL || tab[0] == space)
	return (0);

if (tab[1] == NULL || tab[1] == space)
	return (1);

liase = tab[1];
while (liase[i])
{
	if (liase [i] == *apostro)
	{
		if (i > 0 && liase[i - 1] == '\\')
		{
			i++;
			continue;
		}
		else
		{
			flag = !flag;
			i++;
			continue;
		}
	}
	i++;
}
if (flag == 0)
	return (2);
for (i = 0; tab[i]; i++)
	free(tab[i]);
free(tab);

return (0); /** don't proceed. unterminated value */
}
