#include <stdio.h>
int main()
{
    float fahr, celsius;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    printf("Fahr  Celsius\n");
    for (fahr = upper; fahr >= lower; fahr -= step)
    {
        printf("%3.0f  %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }
    return 0;
}