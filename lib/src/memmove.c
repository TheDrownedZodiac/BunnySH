/*
 * E89 Pedagogical & Technical Lab
 * project:     day2
 * created on:  2023-02-01 - 11:25 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: memmove
 */

#include "fonction.h"

void *stu_memmove(void *dest,
                  const void *src,
                  unsigned int n)
{
    unsigned int count;
    char *str_1;
    char *str_2;

    count = 0;
    str_1 = (char *) dest;
    str_2 = (char *) src;
    if (str_1 < str_2) {
        while (count < n) {
            str_1[count] = str_2[count];
            count += 1;
        }
        return dest;
    }
    count = n;
    while (count > 0) {
        str_1[count - 1] = str_2[count - 1];
        count -= 1;
    }
    return dest;
}
