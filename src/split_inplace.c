/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_getline
 * created on:  2023-02-28 - 17:22 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: split in place
 */

#include <stddef.h>

char *split_inplace(char *str, char token)
{
    int i;

    i = 0;
    while (str[i] != '\0'){
        if (str[i] == token) {
            str[i] = '\0';
            if (str[i + 1] == '\0') {
                return "";
            }
            return &str[i + 1];
        }
        i += 1;
    }
    if (token == '\0') {
        return &str[i + 1];
    }
    return NULL;
}
