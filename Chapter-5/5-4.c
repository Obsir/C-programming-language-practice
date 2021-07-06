#include <stdio.h>

int my_strend(char *s, char *t)
{
    char *bs = s;
    char *bt = t;
    for (; *s; s++)
        ;
    for (; *t; t++)
        ;
    for (; *s == *t; s--, t--)
        if (t == bt || s == bs)
            break;

    if (*s == *t && t == bt && *s != '\0')
        return 1;
    else
        return 0;
}

int main()
{
    char s[] = "Hello World";
    char t[] = "World";
    printf("%d\n", my_strend(s, t));
    return 0;
}