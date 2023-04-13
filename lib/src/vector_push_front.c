/*
 * E89 Pedagogical & Technical Lab
 * project:     day3
 * created on:  2023-02-06 - 10:29 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: vector push front
 */

#include "fonction.h"

void *stu_vector_push_front(stu_vector_t *ve, void *elem)
{
    return stu_vector_insert_at(ve, 0, elem);
}
