#include <stdio.h>
#define IN 1
#define OUT 0
#define MAXHIST 15
#define MAXWORD 11
int main()
{
    int c, i, nc, state;
    int len;
    int maxvalue;
    int overflow;
    int w1[MAXWORD];
    state = OUT;
    nc = 0;
    overflow = 0;
    for (i = 0; i < MAXWORD; i++)
        w1[i] = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
            if (nc > 0)
            {
                if (nc < MAXWORD)
                {
                    ++w1[nc];
                }
                else
                {
                    ++overflow;
                }
            }
        }
        else if (state == OUT)
        {
            nc = 1;
            state = IN;
        }
        else
        {
            ++nc;
        }
    }

    maxvalue = 0;
    for (i = 1; i < MAXWORD; i++)
    {
        if (w1[i] > maxvalue)
            maxvalue = w1[i];
    }
    for (i = 1; i < MAXWORD; i++)
    {
        printf("%5d - %5d : ", i, w1[i]);
        if (w1[i] > 0)
        {
            if ((len = w1[i] * MAXHIST / maxvalue) <= 0)
            {
                len = 1;
            }
        }
        else
        {
            len = 0;
        }
        while (len > 0)
        {
            putchar('*');
            --len;
        }
        putchar('\n');
    }
    if (overflow > 0)
    {
        printf("There are %d words >= %d\n", overflow, MAXWORD);
    }
    return 0;
}