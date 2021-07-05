#include <stdio.h>
char buf = 0;
int getch(void)
{
    int c;
    if (buf != 0)
    {
        c = buf;
    }
    else
    {
        c = getchar();
    }
    buf = 0;
    return c;
}
void ungetch(int c)
{
    if (buf != 0)
        printf("ungetch: Too many characters!\n");
    else
        buf = c;
}
int main()
{
    return 0;
}