#include "main.h"

/**
 * count_words - Counts the number of words in a string
 * @str: The string to count
 * @delimiter: separator of words
 *
 * Return: The number of words, or 0 if str is NULL or empty
 */
int count_words(char *str, const char *delimiter)
{
int i, count, in_word;

if (str == NULL || str[0] == '\0')
	return (0);

in_word = 0;
count = 0;
for (i = 0; str[i] != '\0'; i++)
{
	if (str[i] == *delimiter)
		in_word = 0;
	else if (in_word == 0)
	{
		in_word = 1;
		count++;
	}
}

return (count);
}

/**
 * copy_word - Copies a word from a string to a new string
 * @str: The source string
 * @start: The starting index of the word
 * @end: The ending index of the word
 *
 * Return: A pointer to the new string, or NULL on failure
 */
char *copy_word(char *str, int start, int end)
{
char *word;
int i, j;

word = malloc(sizeof(char) * (end - start + 2));
if (word == NULL)
	return (NULL);

j = 0;
for (i = start; i <= end; i++)
{
	word[j] = str[i];
	j++;
}
word[j] = '\0';
return (word);
}

/**
 * strtow - Splits a string into words
 * @str: The string to split
 * @delimiter: the separator of words
 *
 * Return: A pointer to an array of strings (words), or NULL on failure
 */

char **strtow(char *str, const char *delimiter)
{
char **tab;
int i, j, k, n_words, start, end;

n_words = count_words(str, delimiter);
if (n_words == 0)
	return (NULL);

tab = malloc(sizeof(char *) * (n_words + 1));
if (tab == NULL)
	return (NULL);

k = 0;
i = 0;
while (k < n_words)
{
	while (str[i] == *delimiter)
		i++;
	start = i;
	while (str[i] != *delimiter && str[i] != '\0')
		i++;
	end = i - 1;
	tab[k] = copy_word(str, start, end);
	if (tab[k] == NULL)
	{
		for (j = 0; j < k; j++)
			free(tab[j]);
		free(tab);
		return (NULL);
	}
	k++;
}
tab[k] = NULL;
return (tab);
}

/**
* _strlen_const - printing the length of a string with read only capacity
* @s: string being dereferenced
*
* Return: 0 if successful
*/

int _strlen_const(const char *s)
{
int i;
for (i = 0 ; *s != '\0' ; i++)
{
        s++;
}

return (i);
}

/**
* _strcmp - comparing two strings
* @str1: first string
* str2: second string
*
* Return: 0 if successful or -1 on failure
*/

int _strcmp(const char *str1, const char *str2)
{
int len1, len2, i;

len1 = _strlen_const(str1);
len2 = _strlen_const(str2);

if (len1 != len2)
	return (-1);

for (i = 0; i < len1; i++)
{
	if (str1[i] != str2[i])
		return (-1);
}

return (0);
}
