#include <stdio.h>
#include "util.h"
/**
 *  斐波那契数列的递归实现
 */
int fib(int n)
{
    int result = 0;
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {

        result = 1;
        return 1;
    }
    result = fib(n - 1) + fib(n - 2);
    return result;
}
int main(int argc, char const *argv[])
{
    printf("%d\n", fib(10));
    printf("%d\n", fib(20));
    printf("%d\n", fib(30));
    printf("%d\n", fib(40));
    return 0;
}
