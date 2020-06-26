/**
 * 考察指针
 */
#include <stdio.h>

int f(int *i, int *j)
{
    *i += 4 + *j;
    printf("%d,%d\n", *i, *j);
    return *i + *j;
}

int main()
{
    int x = 2;
    x = f(&x, &x);
    printf("%d\n", x);
    return 0;
}