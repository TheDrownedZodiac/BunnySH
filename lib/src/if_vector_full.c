/*
 * E89 Pedagogical & Technical Lab
 * project:     day3
 * created on:  2023-02-02 - 11:01 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: if vector full
 */

#include "fonction.h"

void if_vector_full(stu_vector_t *ve)
{
    void *old;

    if (ve->len_total <= ve->len_use) {
        old = malloc(ve->len_total);
        stu_memcpy(old, ve->vector, ve->len_use);
        free(ve->vector);
        ve->vector = malloc(ve->len_total + ve->size);
        stu_memcpy(ve->vector, old, ve->len_use);
        ve->len_total += ve->size;
        free(old);
    }
}
