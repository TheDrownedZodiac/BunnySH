/*
 * E89 Pedagogical & Technical Lab
 * project:     day 204
 * created on:  2023-02-07 - 16:45 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: to each their turn function
 */

#include <unistd.h>
#include <sys/wait.h>

static unsigned int stu_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}

int to_each_their_turn(const char *str)
{
    pid_t fork_res;
    int wstatus;

    fork_res = fork();
    if (fork_res == -1) {
        return (-1);
    }
    if (fork_res == 0) {
        write(1, "child:", 6);
        write(1, str, stu_strlen(str));
        write(1, "\n", 1);
        return (0);
    } else {
        waitpid(0, &wstatus, 0);
        write(1, "parent:", 7);
        write(1, str, stu_strlen(str));
        write(1, "\n", 1);
        return (0);
    }
}
