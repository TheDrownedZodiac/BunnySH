/*
 * E89 Pedagogical & Technical Lab
 * project:     day3
 * created on:  2023-02-03 - 14:11 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: vector get back
 */

#include "fonction.h"

void *stu_vector_get_back(const stu_vector_t *ve)
{
    void *str_1;

    str_1 = ve->vector + ve->len_use;
    return str_1;

}
