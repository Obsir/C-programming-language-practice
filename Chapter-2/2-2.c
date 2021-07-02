#include <stdio.h>
enum loop
{
    NO,
    YES
};
int main()
{
    enum loop okloop = YES;
    int c, i;
    int lim = 1000;
    for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
        ;
    i = 0;
    while (okloop == YES)
    {
        if (i >= lim - 1)
            okloop = NO;
        else if ((c = getchar()) == '\n')
            okloop = NO;
        else if (c == EOF)
            okloop = NO;
        else
        {
            ++i;
        }
    }
    return 0;
}