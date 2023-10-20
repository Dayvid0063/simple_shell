#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <stddef.h>

#define MAX_LINE_LENGTH 1024

extern char **environ;
int main(int arc, char **argv);
int run_setenv(char **tokens);
int run_unsetenv(char **tokens);
int handle_built_in(char **tokens);
int run_env(void);
ssize_t read_command(char **line, size_t *n);
void split_string(char *str);
void execute(char **tokens);
char *search_path(const char *c_name);

#endif
