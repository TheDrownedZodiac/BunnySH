/*
 * E89 Pedagogical & Technical Lab
 * project:     day2
 * created on:  2023-01-31 - 11:04 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: memset
 */

#include "fonction.h"

void *stu_memset(void *ptr, char byte, unsigned int n)
{
    char *str_ptr;
    unsigned int count;

    str_ptr = (char *) ptr;
    count = 0;
    while (count < n) {
        str_ptr[count] = byte;
        count += 1;
    }
    return ptr;
}
