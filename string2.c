#include "shell.h"

/**
 * _strlen - returns the length of a sting
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - performs lexicographic comparison of two strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: negative if s1 < s2, positive if s1 > s2, 0 if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);

	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: thr substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

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
