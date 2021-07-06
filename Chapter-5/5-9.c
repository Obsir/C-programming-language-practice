#include <stdio.h>
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
int day_of_year(int year, int month, int day)
{
    int leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (month < 1 || month > 12)
        return -1;
    if (day < 1 || day > daytab[leap][month])
        return -1;

    char *p = daytab[leap];
    while (--month)
        day += *++p;
    return day;
}
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap;
    if (year < 1)
    {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    char *p = daytab[leap];
    while (yearday > *++p)
    {
        yearday -= *p;
    }
    *pmonth = p - *(daytab + leap);
    *pday = yearday;
}
int main()
{
    int month, day;
    month_day(2008, 364, &month, &day);
    printf("%d - %d\n", month, day);
    return 0;
}