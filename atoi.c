#include "shell.h"
#include <stdio.h>

/**
 * is_interactive - checks for the interactive mode of shell
 * @info: pointer to info struct
 *
 * Return: 1 (Success), 0 (Failure)
 */

int is_interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delimiter - tests if a character is a delimiter
 * @c: the character to test
 * @delim: the delimiter string
 *
 * Return: 1 (Success), 0 (Failure)
 */

int is_delimiter(char c, char *delim)
{
	while (*delim != '\0')
	{
	if (*delim == c)
	return (1);
	delim++;
	}
	return (0);
}

/**
 * is_alpha_char - confirms if a character is an alphabet
 * @c: the character to check
 *
 * Return: 1 (Success), 0 (Failure)
 */

int is_alpha_char(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * string_to_int - changes a string to an integer
 * @s: the string to be changed
 *
 * Return: 0 if no numbers are present, or a number if present on string
 */

int string_to_int(char *s)
{
	int sign = 1, flag = 0;
	unsigned int result = 0;

	while (*s != '\0' && flag != 2)
	{
	if (*s == '-')
	sign *= -1;

	if (*s >= '0' && *s <= '9')
	{
	flag = 1;
	result = result * 10 + (*s - '0');
	}
	else if (flag == 1)
	{
	flag = 2;
	}
	s++;
	}

	return ((sign == -1) ? -result : result);
}
/**
 * main - entry point
 *
 * Return: 0 (Success)
 */

int main(void)
{
info_t info;
/* Initializes the info struct */

if (is_interactive(&info))
{
/* handles interactive mode */
printf("Running in interactive mode\n");
}
else
{/* handles the non-interactive mode */
printf("Running in non-interactive mode\n");
	}
/* function calls */

return (0);
}
