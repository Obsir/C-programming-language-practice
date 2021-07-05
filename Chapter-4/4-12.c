#include <stdio.h>
#include <math.h>
void itoa(int n, char s[])
{
    static int i;
    if (n / 10)
        itoa(n / 10, s);
    else
    {
        i = 0;
        if (n < 0)
            s[i++] = '-';
    }
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}
void my_itoa(int n, char s[])
{
    static int i = 0;
    if (n < 0)
    {
        s[i++] = '-';
        n = -n;
    }
    if (n / 10)
        my_itoa(n / 10, s);
    s[i++] = n % 10 + '0';
    s[i] = '\0';
}
void main()
{
    char s[10];
    itoa(-123, s);
    printf("%s\n", s);
    my_itoa(-123, s);
    printf("%s\n", s);
}