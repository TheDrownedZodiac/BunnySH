/*
 * E89 Pedagogical & Technical Lab
 * project:     day_104
 * created on:  2023-02-10 - 08:39 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: pipe commands
 */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

struct child {

    pid_t pid;
    pid_t wstatus;
    pid_t out;

};

static void child_f(const char *command, int p, int *pipefd)
{
    int err;

    if (p == 0) {
        close(pipefd[1]);
    } else {
        close(pipefd[0]);
    }
    dup2(pipefd[p], p);
    close(pipefd[p]);
    err = execl("/bin/sh", "sh", "-c", command, NULL);
    if (err == -1) {
        exit(err);
    }
}

static int wait_status(struct child *one, struct child *two)
{
    while (!WIFEXITED(one->wstatus) || !WIFEXITED(two->wstatus)) {
        one->out = waitpid(one->pid, &one->wstatus, 0);
        two->out = waitpid(two->pid, &two->wstatus, 0);
        if (one->out < 0 || two->out < 0){
            return -1;
        }
    }
    return 0;
}

int pipe_commands(const char **commands)
{
    struct child one;
    struct child two;
    int fd[2];

    pipe(fd);
    one.pid = fork();
    if (one.pid == -1) {
        return -1;
    }
    if (one.pid == 0) {
        child_f(commands[0], 1, fd);
    }
    two.pid = fork();
    if (two.pid == -1) {
        return -1;
    }
    if (two.pid == 0) {
        child_f(commands[1], 0, fd);
    }
    close(fd[0]);
    close(fd[1]);
    if (wait_status(&one, &two) == -1) {
        return -1;
    }
    return (WEXITSTATUS(two.wstatus));
}
