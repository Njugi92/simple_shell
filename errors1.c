#include "shell.h"
/**
* _erratoi - The function converts a string to an integer
* @t: this is the string to be converted
* Return: 0 if no numbers in string, converted number otherwise
* -1 on error
*/
int _erratoi(char *t)
{
int j = 0;
unsigned long int result = 0;
if (*t == '+')
t++; /* TODO: why does this make main return 255? */
for (j = 0; t[j] != '\0'; j++)
{
if (t[j] >= '0' && t[j] <= '9')
{
result *= 10;
result += (t[j] - '0');
if (result > INT_MAX)
return (-1);
}
else
return (-1);
}
return (result);
}
/**
* print_error - the function prints an error message
* @info: this is the parameter & return info struct
* @estr: the string containing specified error type
* Return: 0 if no numbers in string, converted number otherwise
* -1 on error
*/
void print_error(info_t *info, char *estr)
{
_eputs(info->fname);
_eputs(": ");
print_d(info->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(info->argv[0]);
_eputs(": ");
_eputs(estr);
}
/**
* print_d - the function prints a decimal (integer) number (base 10)
* @input: it is the input
* @df: it is the filedescriptor to write to
*
* Return: number of characters printed
*/
int print_d(int input, int df)
{
int (*__putchar)(char) = _putchar;
int j, count = 0;
unsigned int _abs_, current;
if (df == STDERR_FILENO)
__putchar = _eputchar;
if (input < 0)
{
_abs_ = -input;
__putchar('-');
count++;
}
else
_abs_ = input;
current = _abs_;
for (j = 1000000000; j > 1; j /= 10)
{
if (_abs_ / j)
{
__putchar('0' + current / j);
count++;
}
current %= j;
}
__putchar('0' + current);
count++;
return (count);
}
/**
* convert_number - it is the converter function, a clone of itoa
* @num: the number
* @base: the base
* @flags: it is the argument flags
*
* Return: the string
*/
char *convert_number(long int num, int base, int flags)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = num;
if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';
}
array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" :
"0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';
do {
*--ptr = array[n % base];
n /= base;
} while (n != 0);
if (sign)
*--ptr = sign;
return (ptr);
}
/**
* remove_comments - the function replaces first instance of '#' with '\0'
* @buffer: the address of the string to modify
*
* Return: 0 (success)
*/
void remove_comments(char *buffer)
{
int j;
for (j = 0; buffer[j] != '\0'; j++)
if (buffer[j] == '#' && (!j || buffer[j - 1] == ' '))
{
buffer[j] = '\0';
break;
}
}
