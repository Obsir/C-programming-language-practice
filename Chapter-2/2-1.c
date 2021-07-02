#include <stdio.h>
#include <limits.h>
int main()
{
    printf("signed char min = %d\t%d\n", SCHAR_MIN, -(char)((unsigned char)~0 >> 1));
    printf("signed char max = %d\t%d\n", SCHAR_MAX, (char)((unsigned char)~0 >> 1));

    printf("signed short min = %d\t%d\n", SHRT_MIN, -(short)((unsigned short)~0 >> 1));
    printf("signed short max = %d\t%d\n", SHRT_MAX, (short)((unsigned short)~0 >> 1));

    printf("signed int min = %d\t%d\n", INT_MIN, -(int)((unsigned int)~0 >> 1));
    printf("signed int max = %d\t%d\n", INT_MAX, (int)((unsigned int)~0 >> 1));

    printf("signed long min = %ld\t%ld\n", LONG_MIN, -(long)((unsigned long)~0 >> 1));
    printf("signed long max = %ld\t%ld\n", LONG_MAX, (long)((unsigned long)~0 >> 1));

    printf("unsigned char max = %u\t%u\n", UCHAR_MAX, (unsigned char)~0);
    printf("unsigned short max = %u\t%u\n", USHRT_MAX, (unsigned short)~0);
    printf("unsigned int max = %u\t%u\n", UINT_MAX, (unsigned int)~0);
    printf("unsigned long max = %lu\t%lu\n", ULONG_MAX, (unsigned long)~0);

    return 0;
}