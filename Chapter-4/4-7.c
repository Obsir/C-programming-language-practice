#include <stdio.h>
#include <string.h>
char buf[BUFSIZ];
int bufp = 0;
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    if (bufp == BUFSIZ)
        printf("ungetch: Too many characters!\n");
    else
        buf[bufp++] = c;
}
void ungets(char s[])
{
    int len = strlen(s);
    while (len > 0)
    {
        ungetch(s[--len]);
    }
}
int main()
{
    char s[] = "Hello World!";
    ungets(s);
    printf("%s\n", buf);
    return 0;
}