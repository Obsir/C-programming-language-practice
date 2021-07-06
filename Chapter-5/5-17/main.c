#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "numcmp.h"
#include "substr.h"

#define NUMERIC 1
#define DECR 2
#define FOLD 4
#define DIR 8
#define LINES 100
char option = 0;
int pos1 = 0;
int pos2 = 0;
void readargs(int argc, char *argv[]);
int readlines(char *lineptr[], int maxlines);
void my_qsort(void *v[], int left, int right, int (*comp)(void *, void *));
void writelines(char *lineptr[], int nlines, int decr);
void swap(void *v[], int i, int j);
int getline(char *, int);

int main()
{
    char *lineptr[LINES];
    int nlines;
    int c, rc = 0;

    /* test options */
    int argc = 4;
    char *ops[] = {"main", "-fdr", "+0", "-1"};
    char **argv = ops;

    readargs(argc, argv);
    if ((nlines = readlines(lineptr, LINES)) > 0)
    {
        if (option & NUMERIC)
            my_qsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))numcmp);
        else
            my_qsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))charcmp);
        writelines(lineptr, nlines, option & DECR);
    }
    else
    {
        printf("input too big to sort\n");
        rc = -1;
    }

    return rc;
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
void writelines(char *lineptr[], int nlines, int decr)
{
    int i;
    if (decr)
    {
        for (i = nlines - 1; i >= 0; i--)
            printf("%s\n", lineptr[i]);
    }
    else
    {
        for (i = 0; i < nlines; i++)
            printf("%s\n", lineptr[i]);
    }
}

void swap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void my_qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
    {
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    my_qsort(v, left, last - 1, comp);
    my_qsort(v, last + 1, right, comp);
}

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[LINES];
    nlines = 0;
    while ((len = getline(line, LINES)) > 0)
        if (nlines >= maxlines || (p = malloc(len * sizeof(char))) == NULL)
            return -1;
        else
        {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

void readargs(int argc, char *argv[])
{
    int c;
    while (--argc > 0 && (c = (*++argv)[0]) == '-' || c == '+')
    {
        if (c == '-' && !isdigit(*(argv[0] + 1)))
            while (c = *++argv[0])
                switch (c)
                {
                case 'd':
                    option |= DIR;
                    break;
                case 'f':
                    option |= FOLD;
                    break;
                case 'n':
                    option |= NUMERIC;
                    break;
                case 'r':
                    option |= DECR;
                    break;
                default:
                    printf("sort: illegal option %c\n", c);
                    error("Usage: sort -dfnr [+pos1] [-pos2]");
                    break;
                }
        else if (c == '-')
            pos2 = atoi(argv[0] + 1);
        else if ((pos1 = atoi(argv[0] + 1)) < 0)
            error("Usage: sort -dfnr [+pos1] [-pos2]");
    }
    if (argc || pos1 > pos2)
        error("Usage: sort -dfnr [+pos1] [-pos2]");
}