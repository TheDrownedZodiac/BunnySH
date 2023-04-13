/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_getline
 * created on:  2023-03-01 - 09:29 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: loop read until
 */

#include "fonction.h"

char *loop_read_until(int fd, char token)
{
    char *buffer;
    char *str;
    int size_read;
    int i;

    buffer = malloc(sizeof(char) * 17);
    str = malloc(sizeof(char) * 1);
    buffer[0] = 0;
    *str = 0;
    size_read = 16;
    while (size_read == 16) {
        i = 0;
        size_read = read(fd, buffer, 16);
        buffer[size_read] = '\0';
        while (buffer[i] != '\0') {
            if (buffer[i] == token) {
                str = strdupcat(str, buffer);
                free(buffer);
                return str;
            }
            i += 1;
        }
        str = strdupcat(str, buffer);
    }
    free(buffer);
    return str;
}
