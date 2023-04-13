/*
 * E89 Pedagogical & Technical Lab
 * project:     day3
 * created on:  2023-02-03 - 14:47 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: get size
 */

#include "fonction.h"

size_t stu_vector_get_size(const stu_vector_t *ve)
{
    unsigned int nbr;

    nbr = ve->len_tab;
    return nbr;
}


