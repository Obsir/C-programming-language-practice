#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define NUMBER '0'
#define MAXVAL 100
#define MAXOP 100
char buf[BUFSIZ];
int bufp = 0;
int sp = 0;
double val[MAXVAL];

int getch(void);
void ungetch(int c);
void ungets(char s[]);
int getop(char *s);
void push(double f);
double pop(void);

void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
        printf("Error: Stack full, can't push %g!\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("Error: Stack empty!\n");
        return 0;
    }
}
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
    int argc = 6;
    char *ops[] = {"expr", "2", "3", "4", "+", "*"};
    char **argv = ops;
    char s[MAXOP];
    double op2;
    while (--argc > 0)
    {
        ungets(" ");
        ungets(*++argv);
        switch (getop(s))
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("Error: Zero divisor!\n");
            break;
        default:
            printf("Error: Unknown command %s!\n", s);
            argc = 1;
            break;
        }
    }
    printf("\t%.8g\n", pop());
    return 0;
}