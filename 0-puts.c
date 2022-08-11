#include "shell.h"

/**
 * _strlen - it gives the length of a string
 * @s: pointer to the string
 * Return: the length of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (s[i])
		i++;

	return (i);
}

/**
 * print_prompt - prints a prompt for the shell
 */
void print_prompt(void)
{
	char *s = "$ ";

	write(1, s, 2);
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
 * _puts - prints a string to stdout
 * @str: pointer to string
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
