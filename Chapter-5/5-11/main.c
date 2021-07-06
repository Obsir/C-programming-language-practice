#include <stdio.h>
#include "settab.h"
#include "tabpos.h"
#define MAXLINE 100
#define TABINC 8
#define YES 1
#define NO 0
void entab(char *tab);

int main(int argc, char *argv[])
{
    char tab[MAXLINE + 1];
    settab(argc, argv, tab);
    entab(tab);
    return 0;
}

void entab(char *tab)
{
    int c, pos;
    int nb = 0;
    int nt = 0;
    for (pos = 1; (c = getchar()) != EOF; pos++)
    {
        if (c == ' ')
        {
            if (tabpos(pos, tab) == NO)
                ++nb;
            else
            {
                nb = 0;
                nt++;
            }
        }
        else
        {
            for (; nt > 0; nt--)
                putchar('\t');
            if (c == '\t')
                nb = 0;
            else
                for (; nb > 0; nb--)
                    putchar(' ');
            putchar(c);
            if (c == '\n')
                pos = 0;
            else if (c == '\t')
                while (tabpos(pos, tab) != YES)
                    ++pos;
        }
    }
}

void detab(char *tab)
{
    int c, pos = 1;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            do
            {
                putchar(' ');
            } while (tabpos(pos++, tab) != YES);
        }
        else if (c == '\n')
        {
            putchar(c);
            pos = 1;
        }
        else
        {
            putchar(c);
            ++pos;
        }
    }
}