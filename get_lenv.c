#include "shell.h"

/**
 * shows_path - the path to handl path. fhm.
 * @path: the command to be stored.
 *
 * Return: NULL
 */

char *shows_path(char *path)
{
	size_t len_n = _strlen(path);
	char **nov;

	for (nov = environ; *nov != NULL; ++nov)
	{
		if (_strncmp(*nov, path, len_n) == 0 && (*nov)[len_n] == '=')
			return (&((*nov)[len_n + 1]));
	}
	return (NULL);
}

/**
 * handle_path - The function to handle path.
 * @mycom: the command.
 *
 * Return: NULL.
 */

char *handle_path(char *mycom)
{
	char *path, *fullpath, *pathdir;
	int i = 0;
	struct stat buff;

	while (mycom[i])
	{
		if (mycom[i] == '/')
		{
			if (stat(mycom, &buff) == 0)
				return (_strdup(mycom));
			else
				return (NULL);
		}
		i++;
	}
	path = shows_path("PATH");
	if (!path)
		return (NULL);

	pathdir = strtok(path, ":");
	for (; pathdir != NULL; pathdir = strtok(NULL, ":"))
	{
		fullpath = malloc(_strlen(pathdir) + _strlen(mycom) + 2);
		if (fullpath)
		{
			_strcpy(fullpath, pathdir);
			_strcat(fullpath, "/");
			_strcat(fullpath, mycom);

			if (stat(fullpath, &buff) == 0)
			{
				return (fullpath);
			}
			else
				free(fullpath), fullpath = NULL;
		}
	}
	return (NULL);
}
