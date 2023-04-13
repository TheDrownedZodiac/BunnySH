/*
 * E89 Pedagogical & Technical Lab
 * project:     split
 * created on:  2023-04-05 - 12:17 +0200
 * 1st author:  martin.leroy - martin.leroy
 * description: split prune
 */

#include "fonction.h"

int count_not_empty_sub(char **sp,
                        int (*predicate)(const char *))
{
    int i;
    int x;

    x = 0;
    i = 0;
    while (sp[x] != NULL) {
        if (predicate(sp[x]) == 0) {
            i += 1;
        }
        x += 1;
    }
    return i;
}

int if_full_zero(char **sp, int full)
{
    int x;

    x = 0;
    if (full == 0) {
        while (sp[x] != NULL) {
            free(sp[x]);
            sp[x] = NULL;
            x += 1;
        }
        return 1;
    }
    return 0;
}

static void copy_table(char **dest, char **table)
{
    int x;

    x = 0;
    while (table[x] != NULL) {
        dest[x] = table[x];
        table[x] = NULL;
        table[x] = malloc(sizeof(char *) * 1);
        x += 1;
    }
    dest[x] = NULL;
}

void split_prune(char **sp,
                 int (*predicate)(const char *))
{
    int x;
    int full;
    char **str;

    x = 0;
    full = count_not_empty_sub(sp, predicate);
    if (if_full_zero(sp, full) == 1) {
        return;
    }
    str = malloc(sizeof(char *) * (full + 1));
    str[full] = NULL;
    full = 0;
    while (sp[x] != NULL) {
        if (predicate(sp[x]) == 0) {
            str[full] = sp[x];
            full += 1;
        } else {
            free(sp[x]);
        }
        sp[x] = NULL;
        x += 1;
    }
    copy_table(sp, str);
    split_delete(str);
}
