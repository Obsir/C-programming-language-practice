#include <stdio.h>
void escape(char s[], char t[])
{
    int i, j;
    for (i = j = 0; t[i] != '\0'; i++)
    {
        switch (t[i])
        {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        default:
            s[j++] = t[i];
            break;
        }
    }
    s[j] = '\0';
}
void unescape(char s[], char t[])
{
    int i, j;
    for (i = j = 0; t[i] != '\0'; i++)
    {
        switch (t[i])
        {
        case '\\':
            switch (t[++i])
            {
            case 'n':
                s[j++] = '\n';
                break;
            case 't':
                s[j++] = '\t';
                break;
            default:
                s[j++] = '\\';
                s[j++] = t[i];
                break;
            }
            break;
        default:
            s[j++] = t[i];
            break;
        }
    }
    s[j] = '\0';
}
int main()
{
    char t[10] = "string\t\n";
    char s[10];
    char a[10];
    unescape(s, t);
    printf("%s\n", s);
    escape(a, s);
    printf("%s\n", a);
    return 0;
}