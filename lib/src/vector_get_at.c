/*
 * E89 Pedagogical & Technical Lab
 * project:     day3
 * created on:  2023-02-03 - 10:20 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: vector get at
 */

#include "fonction.h"

void *stu_vector_get_at(const stu_vector_t *ve, size_t pos)
{
    void *str_1;

    if (pos > ve->len_tab) {
        return (NULL);
    }
    str_1 = ve->vector + pos * ve->size;
    return str_1;
}
