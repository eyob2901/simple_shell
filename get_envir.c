#include "main.h"
/**
* _getenv - gets an environment variable
* @name: name of the environment variable
* Return: a pointer to a string with the value
*			null if the env variable doesn't exist
*/
char *_getenv(char *name)
{
	unsigned int i, k, len;

	char *value;

	len = _strlen(name);

	k = len + 1;

	/* loop for every envron variable */
	for (i = 0; environ[i] != NULL; i++)
	{
		/* if the name is the same as variable name */
		if (!strncmp(environ[i], name, len))
		{
			value = &(environ[i][k]);
			return (value);
		}
	}
	return (NULL);
}
