#include "shell.h"

/**
 * _myhistory - Displays the history list, one command per line, followed
 *	by line numbers starting at 0.
 * @info: Potential arguments in a structure used to
 *	maintain constant function prototype
 *
 * Return: Always 0.
 */

int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - Unsets an alias.
 * @info: Parameter struct.
 * @str: The string alias unset.
 *
 * Return: 0 on success, 1 on error.
 */

int unset_alias(info_t *info, char *str)
{
	char *p;
	char c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
	return (1);
	c = *p;
	*p = '\0';
	ret = delete_node_at_index(&(info->alias),
	get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - Sets an alias.
 * @info: Parameter struct.
 * @str: The string alias set.
 *
 * Return: 0 on success, 1 on error.
 */

int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
	return (1);
	if (!*++p)
	return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - Prints an alias string.
 * @node: The alias node printed.
 *
 * Return: 0 on success, 1 on error.
 */

int print_alias(list_t *node)
{
	char *p;
	char *a;

	if (node)
	{
	p = _strchr(node->str, '=');
	for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
	return (0);
	}
	return (1);
}

/**
 * _myalias - Imitates the alias builtin
 * @info: Potential arguments in a structure used to
 *	 maintain constant function prototype
 *
 * Return: Always 0.
 */

int _myalias(info_t *info)
{
	int i;
	char *p;
	list_t *node;

	if (info->argc == 1)
	{
	node = info->alias;
	while (node)
	{
	print_alias(node);
	node = node->next;
	}
	return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
	p = _strchr(info->argv[i], '=');
	if (p)
	set_alias(info, info->argv[i]);
	else
	print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

