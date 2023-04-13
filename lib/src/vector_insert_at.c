/*
 * E89 Pedagogical & Technical Lab
 * project:     day3
 * created on:  2023-02-03 - 16:01 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: vector insert at
 */

#include "fonction.h"

void *stu_vector_insert_at(stu_vector_t *ve, size_t pos, void *elem)
{
    char *str;
    int len;

    if_vector_full(ve);
    len = ve->len_use - pos * ve->size;
    str = (char *) ve->vector + pos * ve->size;
    stu_memmove(str + ve->size, str, len);
    stu_memcpy(str, elem, ve->size);
    str += ve->size;
    ve->len_use += ve->size;
    ve->len_tab += 1;

    return ve->vector;
}
