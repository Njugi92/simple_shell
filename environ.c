#include "shell.h"
/**
* _myenv - the function prints the current environment
* @info: the structure containing potential arguments. Used to maintain
* constant function prototype.
* Return: 0 (success)
*/
int _myenv(info_t *info)
{
print_list_str(info->env);
return (0);
}
/**
* _getenv - function gets the value of an environ variable
* @info: the structure containing potential arguments. Used to maintain
* @name: it is the env var name
*
* Return: the value
*/
char *_getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *s;
while (node)
{
s = starts_with(node->str, name);
if (s && *s)
return (s);
node = node->next;
}
return (NULL);
}
/**
* _mysetenv - function initializes a new environment variable,
* or modify an existing one
* @info: the structure containing potential arguments. Used to maintain
* constant function prototype.
* Return: 0 (success)
*/
int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguements\n");
return (1);
}
/**
* _myunsetenv - function removes an environment variable
* @info: the structure containing potential arguments. Used to maintain
* constant function prototype.
* Return: 0 (success)
*/
int _myunsetenv(info_t *info)
{
int j;
if (info->argc == 1)
{
_eputs("Too few arguements.\n");
return (1);
}
for (j = 1; j <= info->argc; j++)
_unsetenv(info, info->argv[j]);
return (0);
}
/**
* populate_env_list - the function populates env linked list
* @info: it's structure containing potential arguments. Used to maintain
* constant function prototype.
* Return: 0 (success)
*/
int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t j;
for (j = 0; environ[j]; j++)
add_node_end(&node, environ[j], 0);
info->env = node;
return (0);
}
