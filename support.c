#include "shell.h"

/**
 * free2D - free array
 * @arr: the one who want to free.
 *
*/
void free2D(char **arr)
{
	int i;

	if (arr == NULL)
		return;
	for (i = 0; arr[i]; i++)
		free(arr[i]), arr[i] = NULL;
	free(arr), arr = NULL;
}

/**
 * _strncmp - the function to compare string.
 * @S1: the first string.
 * @S2: the second string.
 * @num: the size of all these string.
 *
 * Return: 0 on seccess, 1 on error
*/
int _strncmp(const char *S1, const char *S2, size_t num)
{
	size_t i;

	for (i = 0; i < num; i++)
	{
		if (S1[i] != S2[i])
			return (S1[i] - S2[i]);
		if (S1[i] == '\0')
			return (0);
	}
	return (0);
}

/**
 * _itoa - the function to convert integer to ascci
 * @n: the number of ascci.
 *
 * Return: the word who converted.
*/
char *_itoa(int n)
{
	char buff[10];
	int i = 0;

	if (n == 0)
		buff[i++] = '0';
	else
	{
		while (n > 0)
		{
			buff[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buff[i] = '\0';
	rev_str(buff, i);

	return (_strdup(buff));
}

/**
 * rev_str - reverse the string
 * @str: the string
 * @len: lenght of the string
 * Return: void
*/

void rev_str(char *str, int len)
{
	char tmp;
	int st = 0;
	int end = len - 1;

	while (st < end)
	{
		tmp = str[st];
		str[st] = str[end];
		str[end] = tmp;
		st++;
		end--;
	}
}

