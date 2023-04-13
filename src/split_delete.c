/*
 * E89 Pedagogical & Technical Lab
 * project:     split
 * created on:  2023-03-20 - 14:41 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: split delete
 */

#include "fonction.h"

void split_delete(char **sp)
{
    int n;

    n = 0;
    while (sp[n] != NULL) {
        free(sp[n]);
        n += 1;
    }
    free(sp);
}
