#include "shell.h"

/**
 * get_environ - Returns the string array copy of our environ.
 *
 * @info: The structure containing potential arguments.
 *
 * Return: The environment.
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return info->environ;
}

/**
 * _unsetenv - Remove an environment variable.
 *
 * @info: The structure containing potential arguments.
 * @var: The string env var property.
 *
 * Return: 1 on delete, 0 otherwise.
 */
int _unsetenv(info_t *info, char *var)
{
	list_t **head = &info->env;
	list_t *node = *head;
	size_t i = 0;

	if (!node || !var)
		return 0;

	while (node)
	{
		char *p = starts_with(node->str, var);

		if (p && *p == '=')
		{
			delete_node_at_index(head, i);
			info->env_changed = 1;
			node = *head;
			continue;
		}

		node = node->next;
		i++;
	}

	return info->env_changed;
}

/**
 * _setenv - Initialize a new environment variable or modify an existing one.
 *
 * @info: The structure containing potential arguments.
 * @var: The string env var property.
 * @value: The string env var value.
 *
 * Return: Always 0.
 */
int _setenv(info_t *info, char *var, char *value)
{
	if (!var || !value)
		return 0;

	char *buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return 1;

	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);

	list_t **head = &info->env;
	list_t *node = *head;
	while (node)
	{
		char *p = starts_with(node->str, var);

		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return 0;
		}

		node = node->next;
	}

	add_node_end(head, buf, 0);
	free(buf);
	info->env_changed = 1;

	return 0;
}
