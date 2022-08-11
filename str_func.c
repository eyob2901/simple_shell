#include "main.h"
/**
* _puts - mimic puts function
* return : void
* @str: string to be printed
*/
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * *_strcmp - compares two strings
 * @s1: the first char pointer
 * @s2: the second char pointer
 * Return: 0 if they're equal, any other integer otherwise
 */
int _strcmp(char *s1, char *s2)
{
	int i, dif;

	dif = 0;
	for (i = 0; (s1[i] != '\0') || (s2[i] != '\0'); i++)
	{
		dif = s1[i] - s2[i];
		if (s1[i] != s2[i])
			return (dif);
	}
	return (dif);
}
