/*
 * E89 Pedagogical & Technical Lab
 * project:     day3
 * created on:  2023-02-03 - 11:49 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: vector get front
 */

#include "fonction.h"

void *stu_vector_get_front(const stu_vector_t *ve)
{
    void *str_1;

    str_1 = ve->vector;
    return str_1;
}
