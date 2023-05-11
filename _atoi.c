#include "shell.h"
/**
 * interactive - it returns true if shell is interactive mode
 * @info: this is struct address
 * Return: 1 if interactive mode , 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * is_delim - it checks if char is a delimeter
 * @a:This is the char to check in to
 * @delim: it is the delimeter string
 * Return: 1 (true), 0 (false)
 */

int is_delim(char a, char *delim)
{
	while (*delim)
		if (*delim++ == a)
			return (1);
	return (0);
}
/**
 * _isalpha - it checks for alphabetic char
 * @k: this is the char to input
 * Return: 1 if k is alphabetic char,0 otherwise
 */

int _isalpha(int k)
{
	if ((k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * _atoi - It converts a string to an int
 * @t: this is the string to be converted
 * Return: 0 if no numbers in string, converted otherwise
 */
int _atoi(char *t)
{
	int j, sign = 1, flag = 0, output;
	unsigned int res = 0;

	for (j = 0; t[j] != '\0' && flag != 2; j++)
	{
		if (t[j] == '-')
			sign *= -1;
	if (t[j] >= '0' && t[j] <= '9')
	{
		flag = 1;
		res *= 10;
		res += (t[j] - '0');
	}
	else if (flag == 1)
		flag = 2;
	}
	if (sign == -1)
		output = -res;
	else
		output = res;
	return (output);
}
