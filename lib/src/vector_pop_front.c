/*
 * E89 Pedagogical & Technical Lab
 * project:     day3
 * created on:  2023-02-06 - 11:03 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: vector pop front
 */

#include "fonction.h"

void stu_vector_pop_front(stu_vector_t *ve)
{
    stu_vector_erase_at(ve, 0);
    return;
}
