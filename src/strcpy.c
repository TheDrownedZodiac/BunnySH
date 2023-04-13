/*
 * E89 Pedagogical & Technical Lab
 * project:     Immersion
 * created on:  2022-09-30 - 14:58 +0200
 * 1st author:  martin.leroy - martin.leroy
 * description: copier une chaîne
 */

char *stu_strcpy(char *dest, const char *src)
{
    int i;

    i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return dest;
}
