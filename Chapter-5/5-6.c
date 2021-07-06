#include <stdio.h>
#include <ctype.h>
#include <string.h>

int getline(char *s, int lim);
int atoi(char *s);
void reverse(char *s);
void itoa(int n, char *s);
int strindex(char *s, char *t);
double atof(char *s);

int getch(void);
void ungetch(int);
#define BUFSIZE 100
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

int getline(char *s, int lim)
{
    int c;
    char *t = s;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - t;
}

int atoi(char *s)
{
    int n, sign;
    for (; isspace(*s); s++)
        ;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;
    for (n = 0; isdigit(*s); s++)
        n = 10 * n + (*s - '0');
    return sign * n;
}

void itoa(int n, char *s)
{
    int sign;
    char *t = s;
    if ((sign = n) < 0)
        n = -n;
    do
    {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse(t);
}

void reverse(char *s)
{
    int c;
    char *t;
    for (t = s + (strlen(s) - 1); s < t; s++, t--)
    {
        c = *s;
        *s = *t;
        *t = c;
    }
}

int strindex(char *s, char *t)
{
    char *b = s;
    char *p, *r;
    for (; *s != '\0'; s++)
    {
        for (p = s, r = t; *r != '\0' && *p == *r; p++, r++)
            ;
        if (r > t && *r == '\0')
        {
            return s - b;
        }
    }
    return -1;
}

double atof(char *s)
{
    double val, power;
    int sign;
    for (; isspace(*s); s++)
        ;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;
    for (val = 0.0; isdigit(*s); s++)
        val = 10.0 * val + (*s - '0');
    if (*s == '.')
        s++;
    for (power = 1.0; isdigit(*s); s++)
    {
        val = 10.0 * val + (*s - '0');
        power *= 10.0;
    }
    return sign * val / power;
}

#define NUMBER '0'

int getop(char *s)
{
    int c;
    while ((*s = c = getch()) == ' ' || c == '\t')
        ;
    *(s + 1) = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    if (isdigit(c))
        while (isdigit(*++s = c = getch()))
            ;
    if (c == '.')
        while (isdigit(*++s = c = getch()))
            ;
    *s = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}