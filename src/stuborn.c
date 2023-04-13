/*
 * E89 Pedagogical & Technical Lab
 * project:     day 204
 * created on:  2023-02-09 - 11:03 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: stuborn
 */

#include <unistd.h>
#include <signal.h>

void handling(int sig)
{
    (void) sig;
    write(1,"i just ignored Ctrl C\n", 23);
}

int stuborn(void)
{
    struct sigaction s;

    s.sa_flags = 0;
    s.sa_handler = handling;
    sigaction(SIGINT, &s, 0);
    sleep(10);
    write(1, "after sleep\n", 12);
    return (0);
}
