/*
 * E89 Pedagogical & Technical Lab
 * project:     day3
 * created on:  2023-02-06 - 11:07 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: vector erase at
 */

#include "fonction.h"

void stu_vector_erase_at(stu_vector_t *ve, size_t pos)
{
    char *str;
    int len;

    len = ve->len_use - pos * ve->size;
    str = (char *) ve->vector + pos * ve->size;
    stu_memmove(str, str + ve->size, len);
    str -= ve->size;
    ve->len_use -= ve->size;
    ve->len_tab -= 1;
    return;
}
