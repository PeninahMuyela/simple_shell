#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
* my_cd - Change directory command
* @argv: Array of command-line arguments
*
* Return: 0 on success, 1 on failure
*/
int my_cd(char *argv[])
{
char *dir;
char buffer[1024];
int chdir_ret;

if (!argv[1])
{
dir = getenv("HOME");
if (!dir)
dir = getenv("PWD");
if (!dir)
dir = "/";
}
else if (strcmp(argv[1], "-") == 0)
{
dir = getenv("OLDPWD");
if (!dir)
{
printf("No previous working directory.\n");
return (1);
}
printf("%s\n", dir);
}
else
{
dir = argv[1];
}

chdir_ret = chdir(dir);

if (chdir_ret == -1)
{
printf("Can't cd to %s\n", dir);
}
else
{
setenv("OLDPWD", getenv("PWD"), 1);
getcwd(buffer, sizeof(buffer));
setenv("PWD", buffer, 1);
}

return (0);
}

/**
* my_help - Help command
*
* Return: 0
*/
int my_help(void)
{
printf("Help function not yet implemented.\n");
return (0);
}

/**
* main - Entry point
* @argc: Number of command-line arguments
* @argv: Array of command-line arguments
*
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
if (argc > 1)
{
if (strcmp(argv[1], "cd") == 0)
{
my_cd(argv);
return (0);
}
else if (strcmp(argv[1], "help") == 0)
{
my_help();
return (0);
}
}

return (0);
}

