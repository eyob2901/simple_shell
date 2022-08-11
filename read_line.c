#include "main.h"
/**
* rline - reads a single line from stdin
* @line: the line input
* Return: the string of the line
*/
void rline(char **line)
{
	size_t linesize = 0;
	int bytes_read;

	bytes_read = getline(line, &linesize, stdin);
	/*getline from stdin */
	if ((bytes_read == -1))
	{
		free(line);
		exit(0);
	}

}
