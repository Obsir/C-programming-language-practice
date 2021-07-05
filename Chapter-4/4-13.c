#include <stdio.h>
#include <string.h>
void reverser(char s[], int i, int len)
{
    int c, j;
    j = len - i - 1;
    if (i < j)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        reverser(s, ++i, len);
    }
}
void reverse(char s[])
{
    reverser(s, 0, strlen(s));
}
void main()
{
    char s[] = "Hello World";
    reverse(s);
    printf("%s\n", s);
}