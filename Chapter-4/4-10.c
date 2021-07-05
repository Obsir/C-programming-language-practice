#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define MAXOP 100
#define NUMBER '0'
#define NAME 'n'
int getop(char[]);
void push(double);
double pop(void);
int getline(char[], int);
void clear(void);
void mathfnc(char[]);
void main()
{
    int type, i, var = 0;
    double op1, op2, v;
    char s[MAXOP];
    double variable[26];
    for (i = 0; i < 26; i++)
    {
        variable[i] = 0.0;
    }
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case NAME:
            mathfnc(s);
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
        case '?':
            op2 = pop();
            printf("\t%.8g\n", op2);
            push(op2);
            break;
        case 'c':
            clear();
            break;
        case 'd':
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case 's':
            op1 = pop();
            op2 = pop();
            push(op1);
            push(op2);
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("Error: Zero divisor!\n");
            break;
        case '\n':
            v = pop();
            printf("\t%.8g\n", v);
            break;
        case '=':
            pop();
            if (var >= 'A' && var <= 'Z')
                variable[var - 'A'] = pop();
            else
                printf("Error: No variable name!\n");
            break;
        default:
            if (type >= 'A' && type <= 'Z')
                push(variable[type - 'A']);
            else if (type == 'v')
                push(v);
            else
                printf("Error: Unknown command %s!\n", s);
            break;
        }
        var = type;
    }
}

void mathfnc(char s[])
{
    double op2;
    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0)
    {
        op2 = pop();
        push(pow(pop(), op2));
    }
    else
        printf("Error: %s not supported!\n", s);
}

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

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
void clear(void)
{
    sp = 0;
}

#define MAXLINE 100
int li = 0;
char line[MAXLINE];

int getline(char line[], int limit)
{
    int c, i;
    for (i = 0; i < limit - 1 && (c = getchar()) != '\n' && c != EOF; i++)
    {
        line[i] = c;
    }
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}

int getop(char s[])
{
    int c, i;
    if (line[li] == '\0')
    {
        if (getline(line, MAXLINE) == 0)
            return EOF;
        else
            li = 0;
    }
    while ((s[0] = c = line[li++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = line[li++]))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = line[li++]))
            ;

    s[i] = '\0';
    li--;
    return NUMBER;
}