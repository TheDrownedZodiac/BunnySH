/*
 * E89 Pedagogical & Technical Lab
 * project:     day 204
 * created on:  2023-02-07 - 16:45 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: system2 function
 */

#include <stddef.h>
#include <unistd.h>
#include <sys/wait.h>

pid_t g_child_pid;

struct var {

    struct sigaction save;
    struct sigaction s;
    pid_t fork_res;
    int wstatus;
    int out;
    int err;

};

static void handling(int sig)
{
    if (sig == SIGINT) {
        kill(g_child_pid, SIGINT);
    }
}

static int child_f(struct var *var, const char *str)
{
    var->err = execl("/bin/sh", "sh", "-c", str, NULL);
    if (var->err == -1) {
        return (-1);
    }
    return 0;
}

int stu_system2(const char *str)
{
    struct var var;

    sigaction(SIGINT, NULL, &var.save);
    var.fork_res = fork();
    var.s.sa_flags = 0;
    var.s.sa_handler = handling;
    if (var.fork_res == -1) {
        return (-1);
    }
    if (var.fork_res == 0) {
        child_f(&var, str);
        return (0);
    } else {
        g_child_pid = var.fork_res;
        sigaction(SIGINT, &var.s, 0);
        var.out = waitpid(var.fork_res, &var.wstatus, 0);
        while (!WIFEXITED(var.wstatus)) {
            var.out = waitpid(var.fork_res, &var.wstatus, 0);
            if (var.out == -1) {
                return (-1);
            }
        }
        sigaction(SIGINT, &var.save, NULL);
        return (WEXITSTATUS(var.wstatus));
    }
}
