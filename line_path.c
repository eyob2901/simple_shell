#include "main.h"

/**
* printpath - prints each directory contained in the environment variable PATH
* Return: the head of the list. null otherwise
*/
path *listpath()
{
	char *pathvalue = _getenv("PATH");
	char *token = strtok(pathvalue, ":");
	unsigned int i;
	path *tail;
	path *head = malloc(sizeof(path));

	if (pathvalue == NULL || head == NULL)
	{
		free(head);
		return (NULL);
	}

	head->str = pathvalue;
	head->next = NULL;
	tail = head;
	for (i = 0; token != NULL; i++)
	{
		tail = add_node_end(tail, token);

		token = strtok(NULL, ":");
	}
	return (head);
}

/**
* add_node_end - adds a node
* @tail: the last node
* @tok: the token string
* Return: the new node of the list. null otherwise
*/
path *add_node_end(path *tail, char *tok)
{
	path *new = malloc(sizeof(path));

	if (tok == NULL || tail == NULL)
	{
		free(new);
		return (NULL);
	}
	new->str = tok;
	new->next = NULL;
	tail->next = new;
	return (new);
}

/**
* free_list - frees a linked list
* @head: the head of the list
*/
void free_list(path *head)
{
	path *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
