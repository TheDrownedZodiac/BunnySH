/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_getline
 * created on:  2023-03-01 - 08:58 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: strdupcat
 */

#include <stddef.h>
#include <stdlib.h>

static char *stu_strcpy(char *dest, const char *src)
{
    int i;

    i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return dest;
}

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

static char *stu_strcat(char *dest, const char *src)
{
    int i;
    int j;

    i = stu_strlen(dest);
    j = 0;
    while (src[j] != '\0') {
        dest[i] = src[j];
        i = i + 1;
        j = j + 1;
    }
    dest[i] = '\0';
    return dest;
}

char *strdupcat(const char *s1, const char *s2)
{
    char *str;

    str = malloc(sizeof(char) * (stu_strlen(s1) + stu_strlen(s2)));
    str[0] = 0;
    stu_strcpy(str, s1);
    stu_strcat(str, s2);
    return (str);
}
