#include "shell.h"

/**
 * clear_info - Initializes info_t struct.
 *
 * @info: The struct address to be initialized.
 */
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_info - Sets the fields of info_t struct.
 *
 * @info: The struct address to be updated.
 * @av: The argument vector.
 */
void set_info(info_t *info, char **av)
{
	info->fname = av[0];

	if (info->arg)
	{
		ffree(info->argv);
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}

		for (int i = 0; info->argv && info->argv[i]; i++)
			info->argc++;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info - Frees the fields of info_t struct.
 *
 * @info: The struct address to be freed.
 * @all: True if freeing all fields.
 */
void free_info(info_t *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;

	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);

		free_list(&(info->env));
		free_list(&(info->history));
		free_list(&(info->alias));

		ffree(info->environ);
		info->environ = NULL;

		bfree((void **)info->cmd_buf);

		if (info->readfd > 2)
			close(info->readfd);

		_putchar(BUF_FLUSH);
	}
}
