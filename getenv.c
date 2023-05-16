#include "shell.h"
/**
* get_environ - the function returns the string array copy of our environ
* @info: the structure containing potential arguments. Used to maintain
* constant function prototype.
* Return: 0 (success)
*/
char **get_environ(info_t *info)
{
if (!info->environ || info->env_changed)
{
info->environ = list_to_strings(info->env);
info->env_changed = 0;
}
return (info->environ);
}
/**
* _unsetenv - function removes an environment variable
* @info: the structure containing potential arguments. Used to maintain
* constant function prototype.
* Return: 1 on the delete, 0 otherwise
* @var: this is the string env var property
*/
int _unsetenv(info_t *info, char *var)
{
list_t *node = info->env;
size_t j = 0;
char *a;
if (!node || !var)
return (0);
while (node)
{
a = starts_with(node->str, var);
if (a && *a == '=')
{
info->env_changed = delete_node_at_index(&(info->env), j);
j = 0;
node = info->env;
continue;
}
node = node->next;
j++;
}
return (info->env_changed);
}
/**
* _setenv - function initializes a new environment variable,
* or modify an existing one
* @info: the structure containing potential arguments. Used to maintain
* constant function prototype.
* @var: this is the string env var property
* @value: it is the string env var value
* Return: 0 (success)
*/
int _setenv(info_t *info, char *var, char *value)
{
char *buffer = NULL;
list_t *node;
char *a;
if (!var || !value)
return (0);
buffer = malloc(_strlen(var) + _strlen(value) + 2);
if (!buffer)
return (1);
_strcpy(buffer, var);
_strcat(buffer, "=");
_strcat(buffer, value);
node = info->env;
while (node)
{
a = starts_with(node->str, var);
if (a && *a == '=')
{
free(node->str);
node->str = buffer;
info->env_changed = 1;
return (0);
}
node = node->next;
}
add_node_end(&(info->env), buffer, 0);
free(buffer);
info->env_changed = 1;
return (0);
}
