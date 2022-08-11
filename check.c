#include "main.h"

/**
 * _check - checks the existence of a file in the current directory
 *@filename: file to be checked
 * Return: 0;
 */
int _check(char *filename)
{
	struct stat st;
	int err = stat(filename, &st);

	if (err == 0)
		puts(" FOUND\n");
	else
		puts("NOT FOUND\n");
	return (0);
}
