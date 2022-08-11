#include "main.h"

/**
* main - prints "$ ", wait for the user to enter a command, execute it
* Return: 0 on success. -1 otherwise
*/
int main(void)
{
int err;

while (1)
{
char *line = NULL, **words = NULL;

_puts("($) ");
rline(&line);

words = split(line);

if (words == NULL || line == NULL)
{
free(line);
free(words);
continue;
}

if (checkbuilt(words) == 0)
{
free(words);
free(line);
continue;
}

err = exec(words);
if (err == -1)
{
puts("error in execution\n");
}
free(line);
free(words);
words = NULL;
line = NULL;
}
}
