/*
 * E89 Pedagogical & Technical Lab
 * project:     split
 * created on:  2023-03-20 - 14:45 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: split print
 */

#include "fonction.h"

void split_print(char **sp)
{
    int n;

    n = 0;
    while (sp[n] != NULL) {
        puts_plus(1, sp[n], 1);
        n += 1;
    }
}
