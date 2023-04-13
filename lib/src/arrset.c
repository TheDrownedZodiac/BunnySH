/*
 * E89 Pedagogical & Technical Lab
 * project:     day2
 * created on:  2023-02-01 - 09:42 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: arrset
 */

#include "fonction.h"

void *arrset(void *array,
             void *elem,
             unsigned int elem_size,
             unsigned int n)
{
    unsigned int count;
    char *str_1;
    char *str_2;

    count = 0;
    str_1 = array;
    str_2 = elem;
    while (count < n) {
        stu_memcpy(str_1, str_2, elem_size);
        str_1 += elem_size;
        count += 1;
    }
    return array;
}
