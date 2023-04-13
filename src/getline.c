/*
 * E89 Pedagogical & Technical Lab
 * project:     getline
 * created on:  2023-03-01 - 12:07 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: getline
 */

#include "fonction.h"

static void if_carry(char **carry, char **str, int fd)
{
    char *res;

    res = split_inplace(*carry, '\n');
    if (res == NULL) {
        *str = loop_read_until(fd, '\n');
        *str = strdupcat(*carry, *str);
        *carry = stu_strdup(split_inplace(*str, '\n'));
    } else if (*res == '\0'){
        *str = stu_strdup(*carry);
        *carry = stu_strdup("\0");
    } else {
        *str = stu_strdup(*carry);
        *carry = stu_strdup(res);
    }
}

static char *check_fd(int fd, int *old_fd, char **carry)
{
    if (*old_fd != fd) {
        *old_fd = fd;
        *carry = NULL;
    }
    return *carry;
}

char *stu_getline(int fd)
{
    static char *carry = NULL;
    static int old_fd = 0;
    char *str;

    check_fd(fd, &old_fd, &carry);
    if (carry == NULL) {
        str = loop_read_until(fd, '\n');
        if (*str == '\0') {
            return str;
        }
        carry = stu_strdup(split_inplace(str, '\n'));
    } else if (*carry == '\0') {
        str = strdup("");
    } else {
        str = malloc(sizeof(char) * 1);
        if_carry(&carry, &str, fd);
    }
    return str;
}
