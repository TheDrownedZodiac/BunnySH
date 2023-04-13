/*
 * E89 Pedagogical & Technical Lab
 * project:     split
 * created on:  2023-03-20 - 14:57 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: split size
 */

#include <stddef.h>

unsigned int split_size(const char **sp)
{
    unsigned int i;

    i = 0;
    while (sp[i] != NULL) {
        i += 1;
    }
    return i;
}
