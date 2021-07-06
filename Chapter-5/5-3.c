#include <stdio.h>
void my_strcat(char *s, char *t)
{
    while (*s)
        s++;
    while (*s++ = *t++)
        ;
}
int main()
{
    char s[] = "Hello";
    char t[] = "World";
    my_strcat(s, t);
    printf("%s\n", s);
    return 0;
}