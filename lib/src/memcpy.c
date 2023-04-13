/*
 * E89 Pedagogical & Technical Lab
 * project:     day02
 * created on:  2023-01-31 - 14:29 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: memcpy
 */

#include "fonction.h"

void *stu_memcpy(void *dest,
                 const void *src,
                 unsigned int n)
{
    unsigned int count;
    char *str_1;
    char *str_2;

    count = 0;
    str_1 = (char *) dest;
    str_2 = (char *) src;
    while (count < n) {
        str_1[count] = str_2[count];
        count += 1;
    }
    return dest;
}
