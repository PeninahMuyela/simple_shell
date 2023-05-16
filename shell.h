#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

extern char **environ;

/**
* struct liststr - singly linked list for strings
* @num: the number field
* @str: a string
* @next: pointer to the next node
*/
typedef struct liststr
{
int num;
char *str;
struct liststr *next;
}
list_t;

/**
* struct passinfo - contains information to be passed to functions
* @arg: string generated from getline containing arguments
* @argv: array of strings from arg
* @path: string path for current command
* @argc: the argument count
* @line_count: the line count
* @err_num: the error code for exit()
* @linecount_flag: if on, count this line of input
* @fname: the program filename
* @env: linked list local copy of environ
* @history: the history node
* @alias: the alias node
* @environ: custom modified copy of environ from LL env
* @env_changed: 1 if environ was changed, 0 otherwise
* @status: the return status of the last executed command
* @cmd_buf: address of pointer to cmd ; chain buffer, for memory management
* @cmd_buf_type: CMD_type (||, &&, ;)
* @readfd: the file descriptor from which to read line input
* @histcount: the history line number count
*/

typedef struct passinfo
{
char *arg;
char **argv;
char *path;
int argc;
unsigned int line_count;
int err_num;
int linecount_flag;
char *fname;
list_t *env;
list_t *history;
list_t *alias;
char **environ;
int env_changed;
int status;
char **cmd_buf;
int cmd_buf_type;
int readfd;
int histcount;
}
info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}
/**
* struct builtin - contains a built-in command and its related function
* @type: the built-in command name
* @func: the function pointer to the corresponding built-in function
*/
typedef struct builtin
{
char *type;
int (*func)(info_t *);
}
builtin_table;

int hsh(info_t *info, char **env);
int find_builtin(info_t *info);
void find_cmd(info_t *info);
void fork_cmd(info_t *info);
int loophsh(char **env);
void _eputs(char *str);
int _eputchar(char c);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);
int _strlen(char *str);
int _strcmp
(char *s1, char *s2);
char *starts_with(const char *str, const char *prefix);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
void _puts(char *str);
int _putchar(char c);
char *_strncpy(char *dest, char *src, int n);
char *_strncat(char *dest, char *src, int n);
char *_strchr(char *str, char c);
char **strtow(char *str, char *delims);
char **strtow2(char *str, char delim);
char *_memset(char *str, char c, unsigned int n);
void ffree(char **ptr);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int bfree(void **ptr);
int _atoi(char *str);
int is_delim(char c, char *delims);
int _isalpha(int c);
int interactive(info_t *info);
int _erratoi(char *str);
void print_error(info_t *info, char *msg);
int print_d(int num, int fd);
char *convert_number(long int num, int base, int flags);
void remove_comments(char *str);
int _myexit(info_t *info);
int _mycd(info_t *info);
int _myhelp(info_t *info);
int _myhistory(info_t *info);
int _myalias(info_t *info);
ssize_t get_input(info_t *info);
int _getline(info_t *info, char **lineptr, size_t *n);
void sigintHandler(int sig_num);
void clear_info(info_t *info);
void set_info(info_t *info, char **env);
void free_info(info_t *info, int cmd_executed);
char *_getenv(info_t *info, const char *name);
int _myenv(info_t *info);
int _mysetenv(info_t *info);
int _myunsetenv(info_t *info);
int populate_env_list(info_t *info);
char **get_environ(info_t *info);
int _unsetenv(info_t *info, char *name);
int _setenv(info_t *info, char *name, char *value);
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);
list_t *add_node(list_t **head, const char *str, int num);
list_t *add_node_end(list_t **head, const char *str, int num);
size_t print_list_str(const list_t *head);
int delete_node_at_index(list_t **head, unsigned int index);
void free_list(list_t **head);
size_t list_len(const list_t *head);
char **list_to_strings(list_t *head);
size_t print_list(const list_t *head);
list_t *node_starts_with(list_t *head, char *prefix, char delimiter);
ssize_t get_node_index(list_t *head, list_t *node);
int is_chain(info_t *info, char *line, size_t *start, size_t len);
void check_chain(info_t *info,
char *line, size_t *start, size_t len, size_t end);
int replace_alias(info_t *info);
int replace_vars(info_t *info);
int replace_string(char **str, char *var);

#endif

