#include "main.h"
#include <unistd.h>
/**
* exec - allows a process to execute another program
* @argv: the line splitted into words
* ps: fork returns 0 to the child and pid to the father
* Return: -1 if execution failed, 0 if it worked
*/
int exec(char **argv)
{
	pid_t _fork;
	int status, _wait;

	_fork = fork();
	/*if fork returns 0, that means the child process is running*/
	if (_fork == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror(argv[0]);
			return (-1);
		}
	} /*if fork returns negative number, that means it failed*/
	else if (_fork < 0)
	{
		puts("error in fork");
		return (-1);
	}
	else
	{
		/*wait till the child process ends*/
		_wait = wait(&status);
		if (_wait == -1)
		{
			puts("ERROR: ");
			return (-1);
		}
	}
	return (0);
}
