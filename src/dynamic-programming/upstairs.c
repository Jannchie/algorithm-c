#include <stdio.h>
int climbStairs(int n)
{
    int p = 0, q = 0, r = 1;
    while (n--)
    {
        q = p;
        p = r;
        r = q + p;
    }
    return r;
}
int main(int argc, char const *argv[])
{
    for (int n = 0; n < 30; n++)
    {
        printf("Climb %d stairs has %d diffierent way(s).\n", n, climbStairs(n));
    }
    return 0;
}
