/*
 * E89 Pedagogical & Technical Lab
 * project:     split
 * created on:  2023-04-05 - 12:02 +0200
 * 1st author:  martin.leroy - martin.leroy
 * description: split foreach
 */

#include "fonction.h"

void split_foreach(char **sp,
                   void (*func)(const char *))
{
    int x;

    x = 0;
    while (sp[x] != NULL) {
        func(sp[x]);
        x += 1;
    }
}
