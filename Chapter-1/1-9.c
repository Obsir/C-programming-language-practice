#include <stdio.h>
#define NONBANK 'a'
int main()
{
    int c, lastc;
    lastc = NONBANK;
    while ((c = getchar()) != EOF)
    {
        // if (c != ' ')
        // {
        //     putchar(c);
        // }
        // if (c == ' ')
        // {
        //     if (lastc != ' ')
        //     {
        //         putchar(c);
        //     }
        // }
        // lastc = c;
        if (c != ' ' || lastc != ' ')
            putchar(c);
        lastc = c;
    }
    return 0;
}