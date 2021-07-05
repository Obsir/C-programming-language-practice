#include <stdio.h>
#define swap(t, x, y) \
    {                 \
        t _z;         \
        _z = y;       \
        y = x;        \
        x = _z;       \
    }
int main()
{
    int x = 1;
    int y = 2;
    swap(int, x, y);
    printf("%d, %d", x, y);
    return 0;
}