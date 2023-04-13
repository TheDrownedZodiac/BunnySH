/*
 * E89 Pedagogical & Technical Lab
 * project:     day3
 * created on:  2023-02-02 - 09:16 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: vector delete
 */

#include "fonction.h"

void stu_vector_delete(stu_vector_t *ve)
{
    ve->len_tab = 0;
    ve->len_use = 0;
    ve->len_total = 0;
    ve->ini_size = 0;
    free(ve->vector);
    free(ve);
}
