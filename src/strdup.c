/*
 * E89 Pedagogical & Technical Lab
 * project:     Immersion
 * created on:  2022-09-30 - 17:48 +0200
 * 1st author:  martin.leroy - martin.leroy
 * description: allocation et copie d’une chaîne
 */

#include <stddef.h>
#include <stdlib.h>

static unsigned int stu_strlen(const char *str)
{
    int i;

    i = 0;
    if (str == NULL) {
        return 0;
    }
    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}

char *stu_strdup(const char *src)
{
    int i;
    char *copy;

    i = 0;
    copy = malloc(sizeof(char) * (stu_strlen(src) + 1));
    if (copy == NULL) {
        return NULL;
    }
    while (src[i] != '\0') {
        copy[i] = src[i];
        i = i + 1;
    }
    copy[i] = '\0';
    return copy;
}
