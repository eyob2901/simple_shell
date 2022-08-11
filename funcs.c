#include "main.h"
/**
* _realloc - mimics realloc function
*@ptr: void pointer
*@old_size: previous size
*@new_size: new size
* Return: nothing
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
	unsigned int i;

	if (old_size == new_size)
		return (ptr);

	if (new_size != 0 || ptr == NULL)
	{
		p = malloc(new_size);
		if (p != NULL)
		{
			if (ptr != NULL)
			{
				for (i = 0; i < new_size && i < old_size; i++)
					p[i] = *((char *)(ptr) + i);
			}
			return (p);
		}
	}
	return (ptr);
}
/**
 * _strcpy - copies a string into another
 * @src: the source string pointer
 * @dest: the target string pointer
 *
 * Description: a function that copies the string pointed to by src,
 * including the terminating null byte (\0), to the buffer pointed to by dest
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *p;

	p = dest;
	while (1)
	{
		*dest = *src;
		if (*src == '\0')
			break;
		dest++;
		src++;
	}
	return (p);
}
/**
 * _strlen - returns the length of a string
 * @s: the char type pointer
 * Return: the string length
 */
int _strlen(char *s)
{
	int c;

	c = 0;
	while (*s != '\0')
	{
		s++;
		c++;
	}
	return (c);
}
