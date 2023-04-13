/*
 * E89 Pedagogical & Technical Lab
 * project:     day 201
 * created on:  2023-01-30 - 10:40 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: strlen
 */

#include <stddef.h>

unsigned int stu_strlen(const char *str)
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
