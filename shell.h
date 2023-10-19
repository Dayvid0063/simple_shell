#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <stddef.h>
#include <limits.h>
#include <ctype.h>
#include <sys/types.h>
#include <time.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024

/**
 * struct list - Structure to represent ls
 * @str: string
 * @next: ptr to the next str
 */
typedef struct list
{
	char *str;
	struct list *next;
} list_t;

/**
 * struct info - Structure to represent info
 * @argc: arg count
 * @argv: arg vector
 * @env: environ
 */
typedef struct info
{
	int argc;
	char **argv;
	list_t *env;
} info_t;

extern char **environ;
ssize_t read_command(char **input, size_t *n);
int main(void);
void execute(char **tokens);
int run_exit(char **tokens);
int run_env(void);
ssize_t my_getline(char **lineptr, size_t *n, FILE *m);
int run_unsetenv(char **tokens);
int run_setenv(char **tokens);
int run_cd(char **tokens);
char *search_path(const char *c_name);
int handle_built_in(char **tokens);
void split_string(char *str);

/* customs functions*/
char *my_getenv(const char *var);
void get_path(void);
void *custom_realloc(void *ptr, size_t size);
char *_memcpy(char *dest, char *src, unsigned int n);
char *my_strtok(char *str, const char *delim);
char *my_strdup(const char *str);
int my_strlen(const char *s);
size_t my_strcspn(const char *s, const char *n);
int my_strcmp(char *s1, char *s2);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *my_strcpy(char *dest, const char *src);

#endif
