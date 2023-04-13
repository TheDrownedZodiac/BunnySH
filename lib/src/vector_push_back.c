/*
 * E89 Pedagogical & Technical Lab
 * project:     day3
 * created on:  2023-02-02 - 12:07 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: vector_push_back
 */

#include "fonction.h"

void *stu_vector_push_back(stu_vector_t *ve, void *elem)
{
    char *str_1;

    if_vector_full(ve);
    str_1 = (char *) ve->vector + ve->len_use;
    stu_memcpy(str_1, elem, ve->size);
    str_1 += ve->size;
    ve->len_use += ve->size;
    ve->len_tab += 1;
    return 0;
}
