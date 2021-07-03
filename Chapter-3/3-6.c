#include <stdio.h>
#include <string.h>
#define abs(x) ((x) < 0 ? -(x) : (x))
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
void itoa(int n, char s[], int w)
{
    int i, sign;
    sign = n;
    i = 0;
    do
    {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0)
    {
        s[i++] = '-';
    }
    while (i < w)
    {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}
int main()
{
    int num = -1560;
    char s[10];
    itoa(num, s, 10);
    printf("%s\n", s);
    return 0;
}