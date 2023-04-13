/*
 * E89 Pedagogical & Technical Lab
 * project:     bsh1
 * created on:  2023-04-11 - 12:09 +0200
 * 1st author:  noah.chantin - noah.chantin
 * description: include file
 */

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <signal.h>
#include <assert.h>
#include <math.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <lapin.h>
#include "struct.h"

#ifndef FONCTION_H

#define FONCTION_H

char *stu_strstr(const char *haystack, const char *needle);

int stu_strcmp(const char *s1, const char *s2);

int to_each_their_turn(const char *str);

int stu_system(const char *str);

int stu_system2(const char *str);

int stuborn(void);

int pipe_commands(const char **commands);

char *split_inplace(char *str, char token);

char *strdupcat(const char *s1, const char *s2);

char *loop_read_until(int fd, char token);

char *stu_getline(int fd);

char *stu_strdup(const char *src);

unsigned int stu_strlen(const char *str);

char *stu_strcpy(char *dest, const char *src);

char *stu_strcat(char *dest, const char *src);

char **split(const char *str, char token);

void split_delete(char **sp);

void split_print(char **sp);

unsigned int split_size(const char **sp);

int puts_plus(int channel, const char *str, int rt);

void *stu_memset(void *s, char byte, unsigned int n);

void split_foreach(char **sp, void (*func)(const char *));

void split_prune(char **sp, int (*predicate)(const char *));

char *stu_getenv(const char *name, const char **ev);

#endif /* Toutes les fonctions ont été coder par Noah Chantin*/

