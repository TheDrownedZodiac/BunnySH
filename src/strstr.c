/*
 * E89 Pedagogical & Technical Lab
 * project:     bsh1
 * created on:  2022-10-03 - 17:52 +0200
 * 1st author:  martin.leroy - martin.leroy
 * description: strstr function
 */

#include <stddef.h>

char *stu_strstr(const char *haystack, const char *needle)
{
    int i;
    int j;
    int k;
    char *cast;

    i = 0;
    j = 0;
    k = 0;
    while(haystack[i] != '\0') {
        if (haystack[i] == needle[j]) {
            j = j + 1;
            if (k == -1) {
                k = i;
            }
            if (needle[j] == '\0') {
                cast = (char *)haystack;
                return (&cast[k]);
            }
        } else {
            j = 0;
            k = -1;
        }
        i = i + 1;
    }
    return NULL;
}
