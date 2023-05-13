#include "shell.h"
/**
* _myhistory -This function displays the history lists,each command by line,
* preceded with line numbers, starting at 0.
* @info: it is the structure containing the potential arguments which
* is Used to maintain the constant function prototype.
* Return: 0 (success!)
*/
int _myhistory(info_t *info)
{
print_list(info->history);
return (0);
}
/**
* unset_alias - the function sets alias to string
* @info: it is parameter struct
* @str: this is the string alias
*
* Return: 0 (success!) , 1 on (error)
*/
int unset_alias(info_t *info, char *str)
{
char *a, b;
int ret;

a = _strchr(str, '=');
if (!a)
return (1);
b = *a;
*a = 0;
ret = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*a = b;
return (ret);
}
/**
* set_alias -The function sets alias to string
* @info: it is parameter struct
* @str: this is the string alias
*
* Return: 0 (success), 1 on (error)
*/
int set_alias(info_t *info, char *str)
{
char *a;

a = _strchr(str, '=');
if (!a)
return (1);
if (!*++a)
return (unset_alias(info, str));
unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
* print_alias -This function prints an alias string
* @node: it is the alias node
*
* Return: 0 (success), 1(error)
*/
int print_alias(list_t *node)
{
char *a = NULL, *p = NULL;

if (node)
{
a = _strchr(node->str, '=');
for (p = node->str; p <= a; p++)
_putchar(*p);
_putchar('\'');
_puts(a + 1);
_puts("'\n");
return (0);
}
return (1);
}
/**
* _myalias - This function mimics the alias builtin (man alias)
* @info: it is structure containing the potential arguments which
* is used to maintain the constant function prototype.
* Return: 0 (success)
*/
int _myalias(info_t *info)
{
int j = 0;
char *a = NULL;
list_t *node = NULL;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
for (j = 1; info->argv[j]; j++)
{
a = _strchr(info->argv[j], '=');
if (a)
set_alias(info, info->argv[j]);
else
print_alias(node_starts_with(info->alias, info->argv[j], '='));
}
return (0);
}
