#ifndef _MONTY_H_
#define _MONTY_H_
#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int number_of_words(char *str);
char **_strtok(char *str);
int _strlen(char *s);
void free_maloc(char **array);
void (*f(char *s))(stack_t **stack, unsigned int line_number);
#endif
