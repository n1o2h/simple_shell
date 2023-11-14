#include "shell.h"

/**
 * pos_num - check if the number is positive or not
 * @str: input parameter
 * Return: return 1
*/
int pos_num(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * _atoi - function array to integer
 * @str: array changed
 * Return: number
*/
int _atoi(char *str)
{
	int i, num = 0;

	for (i = 0; str[i]; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (num);
}

