/*
 * E89 Pedagogical & Technical Lab
 * project:     day3
 * created on:  2023-02-01 - 15:48 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: vector new
 */

#include "fonction.h"

stu_vector_t *stu_vector_new(size_t elem_size, size_t initial_capacity)
{
    stu_vector_t *ve;

    ve = malloc(sizeof(struct stu_vector));
    ve->ini_size = initial_capacity;
    ve->size = elem_size;
    ve->len_tab = 0;
    ve->vector = malloc(elem_size * initial_capacity);
    ve->len_total = elem_size * initial_capacity;
    ve->len_use = 0;
    return ve;
}
