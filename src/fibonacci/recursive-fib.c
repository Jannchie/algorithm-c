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

/**
 * 一行的斐波那契数列递归
 * 东大 2015 iii-s-3
 */
int fib_2(int n)
{

    return n < 1 ? 0 : n == 1 ? 1 : fib_2(n - 2) + fib_2(n - 1);
}

int main(int argc, char const *argv[])
{
    printf("%d\n", fib(10));
    printf("%d\n", fib(20));
    printf("%d\n", fib(30));
    printf("%d\n", fib(40));

    printf("%d\n", fib_2(10));
    printf("%d\n", fib_2(20));
    return 0;
}
