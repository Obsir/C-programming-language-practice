#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100
#define TABINC 8
#define YES 1
#define NO 0
int atoi(char *s)
{
    int n, sign;
    for (; isspace(*s); s++)
        ;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;
    for (n = 0; isdigit(*s); s++)
        n = 10 * n + (*s - '0');
    return sign * n;
}
void settab(int argc, char *argv[], char *tab)
{
    int i, pos;
    if (argc <= 1)
        for (i = 1; i <= MAXLINE; i++)
        {
            if (i % TABINC == 0)
                tab[i] = YES;
            else
                tab[i] = NO;
        }
    else
    {
        for (i = 1; i <= MAXLINE; i++)
        {
            tab[i] = NO;
        }
        while (--argc > 0)
        {
            pos = atoi(*++argv);
            if (pos > 0 && pos <= MAXLINE)
                tab[pos] = YES;
        }
    }
}