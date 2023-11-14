#include "shell.h"

/**
 * splitazer - the function to split the command.
 * @read: the command who the user entered.
 *
 * Return: the split command.
 */

char **splitazer(char *read)
{
	char *tok = NULL, *tem = NULL;
	char **cmd = NULL, del[] = " \t\n";
	int count = 0, i = 0;

	if (!read)
		return (NULL);

	tem = _strdup(read);
	tok = strtok(tem, del);
	if (tok == NULL)
	{
		free(read), read = NULL;
		free(tem), tem = NULL;
		return (NULL);
	}

	for (; tok; count++)
	{
		tok = strtok(NULL, del);
	}
	free(tem), tem = NULL;
	cmd = malloc(sizeof(char *) * (count + 1));
	if (!cmd)
	{
		free(read);
		read = NULL;
		return (NULL);
	}

	tok = strtok(read, del);

	for (; tok; i++)
	{
		cmd[i] = _strdup(tok);
		tok = strtok(NULL, del);
	}
	free(read), read = NULL;
	cmd[i] = NULL;
	return (cmd);
}

