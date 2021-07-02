#include <stdio.h>
int wordlength(void)
{
    int i;
    unsigned v = (unsigned)~0;
    for (i = 1; (v = v >> 1) > 0; i++)
        ;
    return i;
}
unsigned rightrot(unsigned x, int n)
{
    int rbit;
    while (n-- > 0)
    {
        rbit = (x & 1) << (wordlength() - 1);
        x = x >> 1;
        x = x | rbit;
    }
    return x;
}

unsigned rightrot(unsigned x, int n)
{
    int rbits;
    if ((n = n % wordlength()) > 0)
    {
        rbits = ~(~0 << n) & x;
        rbits = rbits << (wordlength() - n);
        x = x >> n;
        x = x | rbits;
    }
    return x;
}

int main()
{
    return 0;
}