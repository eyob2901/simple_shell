/*
* Purpose: Simple command line interpreter
* Usage info: To run a command user need to type any command
* Other info: This program use execvp() function to execute a command.
* Additional features: print out errors
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

/* Declarations for getline()*/
char *input = NULL;
size_t capline = 0; /*Capacity*/

/* Declaration for strtok()*/
int i;
char *token;
char *array[512];

/* Display some info to the user at the start*/
void startDisplay(void)
{
printf("**************************************************************\n");
printf("*WELCOME TO THE COMMAND LINE INTERPETER                      *\n");
printf("*TO RUN A COMMAND SIMPLY TYPE YOUR COMMAND AND PRESS 'ENTER' *\n");
printf("*EXAMPLE: ls -a                                              *\n");
printf("*TO EXIT TYPE 'q'                                            *\n");
printf("**************************************************************\n");
}

/* Print out "MY_SHELL"*/
void displayPrompt(void)
{
printf("MY_SHELL : ");
}

/* Divide input line into tokens*/
void makeTokens(char *input)
{
i = 0;
token = strtok(input, "\n ");
while (token != NULL)
{
array[i++] = token; /*Add tokens into the array*/
token = strtok(NULL, "\n ");
}
array[i] = NULL;
}

/* Execute a command*/
void execute(void)
{
int pid = fork(); /*Create a new process*/
if (pid != 0) /*If not successfully completed*/
{
int s;
waitpid(-1, &s, 0); /* Wait for process termination*/
}
else
{
if (execvp(array[0], array) == -1)
{
/*If returned -1 => something went wrong! If not then successful*/
perror("Wrong command");/*Display error message*/
exit(errno);
}
}
}

int main(void)
{
startDisplay();
while (1)
{
displayPrompt(); /*Display a user prompt*/
getline(&input, &capline, stdin); /*Read the user input*/
/* Check if input is empty  */
if (strcmp(input, "\n") == 0)
{
perror("Please type in a command");
continue;
}
makeTokens(input); /*Divide line into tokens */

/* Check if input is "q", if yes then exit shell  */
if (strcmp(array[0], "q") == 0)
{
printf("SYSTEM : Shell is exit\n");
return (0);
}
execute(); /*Call execvp() */
}
}
