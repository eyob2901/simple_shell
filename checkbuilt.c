#include "main.h"
/**
* checkbuilt - looks for builtin functions
* @args: array
* Return: 0 if found and executed, 1 otherwise
*/
int checkbuilt(char **args)
{
	unsigned int i;
	builtins built_in[] = {
	{"exit", shell_exit},
	{"help", shell_help},
	{"env", shell_env},
	{"cd", shell_cd},
	{"_wich", shell_wich},
	{NULL, NULL}
	};


	for (i = 0; built_in[i].command != NULL; i++)
	{
		if (!(_strcmp(args[0], built_in[i].command)))
		{
			built_in[i].func(args);
			return (0);
		}
	}
	return (1);
}
