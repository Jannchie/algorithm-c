/**
 * 递归执行顺序以及优化
 * 东京大学 2014 w-3
 * TODO: 优化该算法
 */
#include <stdio.h>
int T(int x, int y, int z)
{
    printf("T(%d, %d, %d)\n", x, y, z);
    if (x <= y)
    {
        return y;
    }
    else
    {
        return T(T(x - 1, y, z), T(y - 1, z, x), T(z - 1, x, y));
    }
}
int main(int argc, char const *argv[])
{
    int result = T(4, 1, 2);
    printf("%d\n", result);
    return 0;
}
