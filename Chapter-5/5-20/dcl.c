#include "dcl.h"
#include "gettoken.h"
#include "parmdcl.h"
enum
{
    NAME,
    PARENS,
    BRACKETS
};
enum
{
    NO,
    YES
};
extern int tokentype;
extern char token[];
extern char datatype[];
extern char name[];
extern char out[];
extern int prevtoken;

void dcl(void)
{
    int ns;
    for (ns = 0; gettoken() == '*';)
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}

void dirdcl(void)
{
    int type;
    if (tokentype == '(')
    {
        dcl();
        if (tokentype != ')')
            errmsg("error: missing )\n");
    }
    else if (tokentype == NAME)
    {
        if (name[0] == '\0')
            strcpy(name, token);
    }
    else
        prevtoken = YES;
    while ((type = gettoken()) == PARENS || type == BRACKETS || type == '(')
        if (type == PARENS)
            strcat(out, " function returning");
        else if (type == '(')
        {
            strcat(out, " function expecting");
            parmdcl();
            strcat(out, " and returning");
        }
        else
        {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
}

void errmsg(char *msg)
{
    printf("%s", msg);
    prevtoken = YES;
}