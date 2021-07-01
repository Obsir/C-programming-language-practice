#include <stdio.h>
int getline(char line[], int maxline);
int remove_black(char s[]);
#define MAXLINE 1000
int main()
{
    int len;
    char line[MAXLINE];
    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (remove_black(line) > 0)
        {
            printf("%s", line);
        }
    }
    return 0;
}
int remove_black(char s[])
{
    int i = 0;
    while (s[i] != '\n')
        i++;
    i--;
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
    {
        i--;
    }
    if (i >= 0)
    {
        s[++i] = '\n';
        s[++i] = '\0';
    }
    return i;
}
int getline(char s[], int lim)
{
    int c, i, j;
    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
    {
        if (i < lim - 2)
        {
            s[j] = c;
            j++;
        }
    }
    if (c == '\n')
    {
        s[j] = c;
        j++;
        i++;
    }
    s[j] = '\0';
    return i;
}