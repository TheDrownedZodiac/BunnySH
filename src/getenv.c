/*
 * E89 Pedagogical & Technical Lab
 * project:     bsh1
 * created on:  2023-04-12 - 10:50 +0200
 * 1st author:  noah.chantin - noah.chantin
 * description: get environment var
 */

#include "fonction.h"

char *stu_getenv(const char *name, const char **ev)
{
    int i;
    char *cpy;

    i = 0;
    while (ev[i]) {
        if (stu_strstr(ev[i], name) != NULL) {
            cpy = stu_strdup(ev[i]);
            cpy = split_inplace(cpy, '=');
            return cpy;
        } else {
            i += 1;
        }
    }
    return NULL;
}
