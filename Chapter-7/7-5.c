#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'

int getop(char s[])
{
    int c, i, rc;
    static char lastc[] = " ";
    sscanf(lastc, "%c", &c);
    lastc[0] = ' ';
    while ((s[0] = c) == ' ' || c == '\t')
    {
        if (scanf("%c", &c) == EOF)
            c = EOF;
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        do
        {
            rc = scanf("%c", &c);
            if (!isdigit(s[++i] = c))
                break;
        } while (rc != EOF);
    if (c == '.')
        do
        {
            rc = scanf("%c", &c);
            if (!isdigit(s[++i] = c))
                break;
        } while (rc != EOF);
    s[i] = '\0';
    if (rc != EOF)
        lastc[0] = c;
    return NUMBER;
}

int getop_v2(char s[])
{
    int c, rc;
    float f;
    while ((rc = scanf("%c", c)) != EOF)
        if ((s[0] = c) != ' ' && c != '\t')
            break;
    s[1] = '\0';
    if (rc == EOF)
        return EOF;
    else if (!isdigit(c) && c != '.')
        return c;
    ungetc(c, stdin);
    scanf("%f", &f);
    sprintf(s, "%f", f);
    return NUMBER;
}