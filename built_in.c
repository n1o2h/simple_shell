#include "shell.h"

/**
 * _binaya_ton - the function to build some thing like this.
 * @cmd: the command to be build it.
 *
 * Return: 0 on seccess, 1 on error.
 */

int _binaya_ton(char *cmd)
{
	char *bin[] = {
		"exit",
		"env",
		NULL
	};
	int i = 0;

	while (bin[i])
	{
		if (_strcmp(cmd, bin[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

/**
 * _bin_handlon - handle exit and other thing is or digi mahnt itchmal.
 * @cmd: command.
 * @argv: the vector.
 * @stat: value of return command.
 * @num: the integer to store error
 *
 */

void _bin_handlon(char **cmd, char **argv, int *stat, int num)
{
	(void)argv;
	(void)num;

	if (_strcmp(cmd[0], "exit") == 0)
		_quit_pro(cmd, stat);
	else if (_strcmp(cmd[0], "env") == 0)
		_environ_write(cmd, stat);
}

/**
 * _quit_pro - the function to quit the programm.
 * @cmd: the command.
 * @stat: the value
 *
 */

void _quit_pro(char **cmd, int *stat)
{
	free2D(cmd);
	exit(*stat);
}

/**
 * _environ_write - this to write environ.
 * @cmd: the command.
 * @stat: the value of return.
 *
 */

void _environ_write(char **cmd, int *stat)
{
	int i = 0;

	while (environ[i])
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 2);
		i++;
	}
	free2D(cmd);
	(*stat) = 0;
}
