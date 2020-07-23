#include <stdio.h>
int fib(int N)
{
    long p = 0, q = 1, r = 1;
    while (N--)
    {
        p = q;
        q = r;
        r = p + q;
    }
    return p;
}

int main(int argc, char const *argv[])
{
    for (int n = 0; n <= 88; n++)
    {
        printf("Fibonacci number: f(%d) is %d\n", n, fib(n));
    }
    return 0;
}
