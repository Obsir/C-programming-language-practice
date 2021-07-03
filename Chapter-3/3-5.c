#include <stdio.h>
#include <string.h>
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
void itob(int n, char s[], int b)
{
    int i, j, sign;
    if ((sign = n) < 0)
    {
        n = -n;
    }
    i = 0;
    do
    {
        j = n % b;
        s[i++] = (j <= 9) ? j + '0' : j - 10 + 'a';
    } while ((n /= b) > 0);
    if (sign < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}
int main()
{
    int n = 23;
    char s[100];
    itob(n, s, 16);
    printf("%s\n", s);
    return 0;
}