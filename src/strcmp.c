/*
 * E89 Pedagogical & Technical Lab
 * project:     Immersion
 * created on:  2022-10-10 - 14:35 +0200
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: strcmp
 */

int stu_strcmp(const char *s1, const char *s2)
{
    while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2) {
        s1 += 1;
        s2 += 1;
    }
    if (*s1 == *s2) {
        return 0;
    } else {
        return *s1 - *s2;
    }
}
