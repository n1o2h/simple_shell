#include "shell.h"

/**
 * error_one - the error function.
 * @ism: the name of shell.
 * @cmd: the wrong command.
 * @num: the number of wrong command.
 */

void error_one(char *ism, char *cmd, int num)
{
	char *ofdix, msg[] = ":not found\n";

	ofdix = _itoa(num);
	write(STDERR_FILENO, ism, _strlen(ism));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, ofdix, _strlen(ofdix));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));

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

