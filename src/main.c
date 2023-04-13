/*
 * E89 Pedagogical & Technical Lab
 * project:     bsh1
 * created on:  2023-04-11 - 10:32 +0200
 * 1st author:  noah.chantin - noah.chantin
 * description: main
 */

#include "fonction.h"
#include "struct.h"

int main(int ac, char **av, char **ev)
{
    int i;

    i = 0;
    /* env */
    while (ev[i]) {
        puts(ev[i]);
        i += 1;
    }
    if (ac > 1) {
        /* cd /-/dir/ */
        if (stu_strcmp(av[1], "cd") == 0) {
            if (av[2] == NULL) {
                chdir(stu_getenv("HOME", (const char **) ev));
            } else if (stu_strcmp(av[2], "-") == 0) {
                chdir(stu_getenv("OLDPWD", (const char **) ev));
            } else {
                chdir(av[2]);
            }
        }
    }
    execl("/bin/sh", "sh", "-c", "ls", (char *) NULL);
    return 0;
}
