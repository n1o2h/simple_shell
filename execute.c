#include "shell.h"

/**
 * error_one - the error function.
 * @ism: the name of shell.
 * @cmd: the wrong command.
 * @num: the number of wrong command.
 */

void error_one(char *ism, char *cmd, int num)
{
	char *ofdix;

	ofdix = _itoa(num);

	write(1, ism, _strlen(ism));
	write(1, ": ", 3);
	write(1, ofdix, _strlen(ofdix));
	write(1, ": ", 3);
	write(1, cmd, _strlen(cmd));
	write(1, ": not found\n", 13);
	free(ofdix);
}

/**
 * execute - the execute function to display all code.
 * @cmd: the command.
 * @argv: the vector.
 * @num: the index to keep track in error.
 *
 * Return: the status of command.
 */

int execute(char **cmd, char **argv, int num)
{
	char *allcmd;
	pid_t boy;
	int stat;

	allcmd = handle_path(cmd[0]);
	if (!allcmd)
	{
		error_one(argv[0], cmd[0], num);
		free2D(cmd);
		return (127);
	}
	boy = fork();
	if (boy == 0)
	{
		if (execve(allcmd, cmd, environ) == -1)
		{
			free(allcmd), allcmd = NULL;
			free2D(cmd);
		}
	}
	else
	{
		waitpid(boy, &stat, 0);
		free2D(cmd);
		free(allcmd), allcmd = NULL;
	}
	return (WEXITSTATUS(stat));
}
