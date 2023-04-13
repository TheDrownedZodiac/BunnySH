/*
 * E89 Pedagogical & Technical Lab
 * project:     day 204
 * created on:  2023-02-07 - 16:45 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: system function
 */

#include <stddef.h>
#include <unistd.h>
#include <sys/wait.h>

int stu_system(const char *str)
{
    pid_t fork_res;
    int wstatus;
    int out;
    int err;

    fork_res = fork();
    if (fork_res == -1) {
        return (-1);
    }
    if (fork_res == 0) {
        err = execl("/bin/sh", "sh", "-c", str, NULL);
        if (err == -1) {
            return (-1);
        }
        return (0);
    } else {
        out = waitpid(fork_res, &wstatus, 0);
        if (out < 0) {
            return -1;
        }
        if (WIFEXITED(wstatus)) {
            return (wstatus = WEXITSTATUS(wstatus));
        }
        return (0);
    }
}
