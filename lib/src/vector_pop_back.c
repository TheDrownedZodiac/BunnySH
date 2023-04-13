/*
 * E89 Pedagogical & Technical Lab
 * project:     day3
 * created on:  2023-02-03 - 09:13 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: vector pop back
 */

#include "fonction.h"

void stu_vector_pop_back(stu_vector_t *ve)
{
    if (ve->len_use == 0) {
        return;
    }
    ve->len_use -= ve->size;
    ve->len_tab -= 1;
}
