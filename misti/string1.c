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
* handle_empty_string
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
int i = 0, flag = 0, len;
char *equal = "=";
char *apostro = "'";
char *liase = NULL;

len = _strlen(lias);
liase = malloc((len + 1) * sizeof(char));
liase = copy_word(lias, 0, (len - 1));

while (liase[i] != '\0')
{
	if (liase[i] == *equal)
	{
		flag = 1;
		continue;
	}
	if (liase[i] == *apostro && flag == 1)
	{
		flag = 2;
		continue;
	}
	if (liase[i] == *apostro && flag == 2)
	{
		flag = 3;
		break;
	}
	i++;
}

if (flag == 0)
	return (1); /** print values rather than assign */

if (flag == 3)
	return (2); /** assign values */

free(liase);
return (0); /** don't proceed. unterminated value */
}
