#include "shell.h"
/**
* get_history_file - the function gets the history file
* @info: the parameter struct
*
* Return: returns the allocated string containg history file
*/
char *get_history_file(info_t *info)
{
char *buffer, *dir;
dir = _getenv(info, "HOME=");
if (!dir)
return (NULL);
buffer = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
if (!buffer)
return (NULL);
buffer[0] = 0;
_strcpy(buffer, dir);
_strcat(buffer, "/");
_strcat(buffer, HIST_FILE);
return (buffer);
}
/**
* write_history - function creates a file, or appends to an existing file
* @info: it is the parameter struct
*
* Return: 1 (success), else -1
*/
int write_history(info_t *info)
{
ssize_t df;
char *filename = get_history_file(info);
list_t *node = NULL;
if (!filename)
return (-1);
df = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(filename);
if (df == -1)
return (-1);
for (node = info->history; node; node = node->next)
{
_putsfd(node->str, df);
_putfd('\n', df);
}
_putfd(BUF_FLUSH, df);
close(df);
return (1);
}
/**
* read_history - the function reads history from file
* @info: it is the parameter struct
*
* Return: the histcount on success, 0 otherwise
*/
int read_history(info_t *info)
{
int j, last = 0, linecount = 0;
ssize_t df, rdlen, fsize = 0;
struct stat st;
char *buffer = NULL, *filename = get_history_file(info);
if (!filename)
return (0);
df = open(filename, O_RDONLY);
free(filename);
if (df == -1)
return (0);
if (!fstat(df, &st))
fsize = st.st_size;
if (fsize < 2)
return (0);
buffer = malloc(sizeof(char) * (fsize + 1));
if (!buffer)
return (0);
rdlen = read(df, buffer, fsize);
buffer[fsize] = 0;
if (rdlen <= 0)
return (free(buffer), 0);
close(df);
for (j = 0; j < fsize; j++)
if (buffer[j] == '\n')
{
buffer[j] = 0;
build_history_list(info, buffer + last, linecount++);
last = j + 1;
}
if (last != j)
build_history_list(info, buffer + last, linecount++);
free(buffer);
info->histcount = linecount;
while (info->histcount-- >= HIST_MAX)
delete_node_at_index(&(info->history), 0);
renumber_history(info);
return (info->histcount);
}
/**
* build_history_list - the function adds entry to a history linked list
* @info: the structure containing potential arguments. Used to maintain
* @buffer: this is the buffer
* @linecount: it is the history linecount, histcount
*
* Return: 0 (success)
*/
int build_history_list(info_t *info, char *buffer, int linecount)
{
list_t *node = NULL;
if (info->history)
node = info->history;
add_node_end(&node, buffer, linecount);
if (!info->history)
info->history = node;
return (0);
}
/**
* renumber_history - it renumbers the history linked list after changes
* @info: the structure containing potential arguments. Used to maintain
*
* Return: the new histcount
*/
int renumber_history(info_t *info)
{
list_t *node = info->history;
int j = 0;
while (node)
{
node->num = j++;
node = node->next;
}
return (info->histcount = j);
}
