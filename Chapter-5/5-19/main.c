#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dcl.h"
#include "gettoken.h"
#define MAXTOKEN 100
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char out[1000];
enum
{
    NAME,
    PARENS,
    BRACKETS
};

int main()
{
    int type;
    char temp[MAXTOKEN];
    while (gettoken() != EOF)
    {
        strcpy(out, token);
        while ((type = gettoken()) != '\n')
        {
            if (type == PARENS || type == BRACKETS)
                strcat(out, token);
            else if (type == '*')
            {
                if ((type = nexttoken()) == PARENS || type == BRACKETS)
                    sprintf(temp, "(*%s)", out);
                else
                    sprintf(temp, "*%s", out);
                strcpy(out, temp);
            }
            else if (type == NAME)
            {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            }
            else
                printf("invalid input at %s\n", token);
        }
        printf("%s\n", out);
    }
    return 0;
}