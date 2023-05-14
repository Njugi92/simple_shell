#include "shell.h"
/**
*       is_chain -the function that test if current char
*       in buffer is a chain delimeter
*       @info: it is the parameter struct
*       @buf: this is the character buffer
*       @p: it is an address of current position in buffer
*
*       Return: 1 if chain delimeter, 0 otherwise
*/
int is_chain(info_t *info, char *buf, size_t *p)
{
size_t i = *p;
if (buf[i] == '|' && buf[i + 1] == '|')
{
buf[i] = 0;
i++;
info->cmd_buf_type = CMD_OR;
}
else if (buf[i] == '&' && buf[i + 1] == '&')
{
buf[i] = 0;
i++;
info->cmd_buf_type = CMD_AND;
}
else if (buf[i] == ';') /* found end of this command */
{
buf[i] = 0; /* replace semicolon to null */ info->cmd_buf_type = CMD_CHAIN;
}
else
return (0);
*p = i;
return (1);
}
/**
*       check_chain - function that checks if we should continue
*       chaining based on last status
*       @info: it's the parameter struct
*       @buf: the character buffer
*       @p: it is an address of current position in buffer
*       @i: starting position in buffer
*       @len: length of buffer
*
*       Return: Void
*/
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
size_t j = *p;
if (info->cmd_buf_type == CMD_AND)
{
if (info->status)
{
buf[i] = 0;
j = len;
}
}
if (info->cmd_buf_type == CMD_OR)
{
if (!info->status)
{
buf[i] = 0;
j = len;
}
}
*p = j;
}
/**
* replace_alias - function that replaces an aliases
* in the tokenized string
*       @info: it's the parameter struct
*
*       Return: 1 if replaced, 0 otherwise
*/
int replace_alias(info_t *info)
{
int j; list_t *node; char *p; for (j = 0; j < 10; j++)
{
node = node_starts_with(info->alias, info->argv[0], '=');
if (!node)
return (0);
free(info->argv[0]);
p = _strchr(node->str, '=');
if (!p)
return (0);
p = _strdup(p + 1);
if (!p)
return (0);
info->argv[0] = p;
}
return (1);
}
/**
*       replace_vars - function that replaces vars in the tokenized string
*       @info: this is the parameter struct
*
*       Return: 1 if replaced, 0 otherwise
*/
int replace_vars(info_t *info)
{
int j = 0;
list_t *node;
for (j = 0; info->argv[j];
j++)
{
if (info->argv[j][0] != '$' || !info->argv[j][1])
continue;
if (!_strcmp(info->argv[j], "$?"))
{ replace_string(&(info->argv[j]),
_strdup(convert_number(info->status, 10, 0)));
continue;
}
if (!_strcmp(info->argv[j], "$$"))
{
replace_string(&(info->argv[j]),
_strdup(convert_number(getpid(), 10, 0)));
continue;
}
node = node_starts_with(info->env, &info->argv[j][1], '=');
if (node)
{
replace_string(&(info->argv[j]), _strdup(_strchr(node->str, '=') + 1));
continue;
}
replace_string(&info->argv[j], _strdup(""));
}
return (0);
}
/**
*       replace_string - it replaces string
*       @old: the address of old string
*       @new: the new string
*
*       Return: 1 if replaced, 0 otherwise
*/
int replace_string(char **old, char *new)
{
free(*old);
*old = new;
return (1);
}
