#include <stdio.h>
#define MAXLINE 1000
int getline(char line[], int maxline);
void reverse(char s[]);
int main()
{
    char line[MAXLINE];
    while (getline(line, MAXLINE) > 0)
    {
        reverse(line);
        printf("%s", line);
    }
    return 0;
}

void reverse(char s[])
{
    int i, j;
    char temp;
    while (s[i] != '\0')
        i++;
    i--;
    if (s[i] == '\n')
        i--;
    j = 0;
    while (j < i)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i--;
        j++;
    }
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