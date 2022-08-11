#include "shell.h"
/**
 * _strdup - returns a pointer to a newly allocated space in memory, which
 * contains a copy of the string given as a parameter
 * @str: pointer to a string
 * Return: pointer to a string
 */
char *_strdup(char *str)
{
	int i, l = 0;
	char *new = NULL;

	if (!str)
	{
		return (NULL);
	}
	while (str[l])
		l++;

	new = malloc(sizeof(char) * l + 1);

	if (!new)
	{
		return (NULL);
	}

	for (i = 0; i < l; i++)
	{
		new[i] = str[i];
	}

	new[l] = '\0';
	return (new);
}

/**
 * str_concat - concats 2 strings in a newly allocated memory
 * @s1: first string
 * @s2: second string
 * Return: pointer to the new string
 */
char *str_concat(char *s1, char *s2)
{
	char *s3 = NULL;
	unsigned int l1 = 0, l2 = 0, i = 0, k = 0;

	l1 = _strlen(s1);
	l2 = _strlen(s2);

	s3 = malloc(sizeof(char) * (l1 + l2 + 1));
	if (s3 == NULL)
		return (NULL);

	if (s1)
	{
		while (i < l1)
		{
			s3[i] = s1[i];
			i++;
		}
	}

	if (s2)
	{
		while (i < (l1 + l2))
		{
			s3[i] = s2[k];
			i++;
			k++;
		}
	}
	s3[i] = '\0';

	return (s3);
}

/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
* _strncmp - compare strings up to n bytes
* @s1: string to compare against
* @s2: string to compare from
* @n: number of bytes to compare
*
* Return: 0 if the strings are different, non-zero if they are the same
*/
int _strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0;

	while (*s1 == *s2 && i < n)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
		i++;
	}
	return (i != n);
}

/**
 * *_strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int len, i;

	len = 0;

	while (src[len] != '\0')
		len++;

	for (i = 0; i < len; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}
