/*
 * E89 Pedagogical & Technical Lab
 * project:     split
 * created on:  2023-03-15 - 08:53 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: split function
 */

#include "fonction.h"

struct tab {
    char **table;
    int size;
};

void count_token(int *num, const char *str, char token)
{
    int pos;

    pos = 0;
    while (str[pos] != '\0') {
        if (str[pos] == token) {
            *num += 1;
        }
        pos += 1;
    }
}

void put_in_table(int pos, int opos, const char *str, struct tab *tab)
{
    int x;

    x = 0;
    if (opos == pos) {
        tab->table[tab->size] = malloc(sizeof(char) * 1);
        tab->table[tab->size][0] = '\0';
    } else {
        tab->table[tab->size] = malloc(sizeof(char) * ((pos - opos) + 1));
        while (opos != pos) {
            tab->table[tab->size][x] = str[opos];
            x += 1;
            opos += 1;
        }
        tab->table[tab->size][x] = '\0';
    }
}

char **split(const char *str, char token)
{
    int pos;
    int old_pos;
    int tok_num;
    struct tab tab;

    pos = 0;
    tok_num = 0;
    tab.size = 0;
    count_token(&tok_num, str, token);
    tab.table = malloc(sizeof(char *) * (tok_num + 2));
    old_pos = 0;
    while (str[pos] != '\0') {
        if (str[pos] == token) {
            put_in_table(pos, old_pos, str, &tab);
            tab.size += 1;
            old_pos = pos + 1;
        }
        pos += 1;
    }
    put_in_table(pos, old_pos, str, &tab);
    tab.table[tok_num + 1] = NULL;
    return tab.table;
}
