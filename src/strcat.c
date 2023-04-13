/*
 * E89 Pedagogical & Technical Lab
 * project:     Immersion
 * created on:  2022-10-03 - 16:45 +0200
 * 1st author:  martin.leroy - martin.leroy
 * description: strcat function
 */

#include <stddef.h>

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

char *stu_strcat(char *dest, const char *src)
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
