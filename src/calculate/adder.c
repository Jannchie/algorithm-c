#include <stdio.h>
int getSum(int a, int b)
{
    int r, c, s;
    while (a)
    {
        // 无符号数才能左移
        c = (unsigned int)(a & b) << 1;
        s = a ^ b;

        a = c;
        b = s;
    }
    // 必须返回b而不是s，以防a初始为0
    return b;
}
int main(int argc, char const *argv[])
{
    int a = -501;
    int b = 312;
    printf("%d + %d = %d\n", a, b, getSum(a, b));
    return 0;
}
