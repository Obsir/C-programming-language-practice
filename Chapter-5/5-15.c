#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define NUMERIC 1
#define DECR 2
#define FOLD 4
#define LINES 100

int numcmp(char *, char *);
int charcmp(char *, char *);
int readlines(char *lineptr[], int maxlines);
void my_qsort(void *v[], int left, int right, int (*comp)(void *, void *));
void writelines(char *lineptr[], int nlines, int decr);
void swap(void *v[], int i, int j);
int getline(char *, int);

static char option = 0;
void main()
{
    char *lineptr[LINES];
    int nlines;
    int c, rc = 0;
    int argc = 2;

    /* test options */
    char *ops[] = {"main", "-fr"};
    char **argv = ops;

    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c)
            {
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
                argc = 1;
                rc = -1;
                break;
            }
    if (argc)
        printf("Usage: sort -fnr \n");
    else
    {
        if ((nlines = readlines(lineptr, LINES)) > 0)
        {
            if (option & NUMERIC)
                my_qsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))numcmp);
            else if (option & FOLD)
                my_qsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))charcmp);
            else
                my_qsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))strcmp);
            writelines(lineptr, nlines, option & DECR);
        }
        else
        {
            printf("input too big to sort\n");
            rc = -1;
        }
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

int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
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

int charcmp(char *s, char *t)
{
    for (; tolower(*s) == tolower(*t); s++, t++)
        if (*s == '\0')
            return 0;
    return tolower(*s) - tolower(*t);
}