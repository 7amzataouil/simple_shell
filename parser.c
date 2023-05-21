#include "shell.h"

/**
 * @info: the info struct
 * @path: path to the file
 * is_cmd - determines if a file is an executable comd
 *
 * Return: 1 if true, 0 to else
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
/**
 * dup_chars - duplicates characters
 * @pathstr: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
    char *buf = (char*) malloc(sizeof(char) * (stop - start + 1));
    if (buf == NULL) return NULL;

    int k = 0;
    for (int i = start; i < stop; i++) {
        if (pathstr[i] != ':') {
            buf[k++] = pathstr[i];
        }
    }
    buf[k] = '\0';

    return buf;
}

/**
 * find_path - finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
    if (pathstr == NULL) return NULL;

    if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
    {
        if (is_cmd(info, cmd))
            return cmd;
    }

    int curr_pos = 0;
    char *path = NULL;
    for (int i = 0; pathstr[i]; i++)
    {
        if (pathstr[i] == ':')
        {
            path = dup_chars(pathstr, curr_pos, i);
            if (*path == '\0')
            {
                _strcpy(path, cmd);
            }
            else
            {
                _strcat(path, "/");
                _strcat(path, cmd);
            }

            if (is_cmd(info, path))
                return path;

            curr_pos = i + 1;
            free(path);
        }
    }

    path = dup_chars(pathstr, curr_pos, _strlen(pathstr));
    if (*path == '\0')
    {
        _strcpy(path, cmd);
    }
    else
    {
        _strcat(path, "/");
        _strcat(path, cmd);
    }

    if (is_cmd(info, path))
        return path;

    free(path);
    return NULL;
}
