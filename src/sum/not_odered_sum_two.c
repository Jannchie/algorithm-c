
#include "util.h"

int sumTwo(int *a, int len, int target)
{
    int *table = malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
    {
        int x = a[i];
        int y = target - x;
        if (table[y] == 1)
        {
            printf("[Found] %d + %d = %d.\n", x, y, target);
            return 1;
        }
        else
        {
            table[x] = 1;
        }
    }
    printf("[Failed] Sum two be %d is not exists.\n", target);
    return 0;
}

int main(int argc, char const *argv[])
{

    int n = 10;
    int *a = getShuffledArray(n);
    printArray(a, n);
    sumTwo(a, n, 5);
    sumTwo(a, n, 19);
    sumTwo(a, n, 20);
    return 0;
}
