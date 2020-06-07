
#include "util.h"

int twoSum(int *a, int len, int target)
{
    int i = 0;
    int j = len - 1;
    while (i < j)
    {
        int sum = a[i] + a[j];
        if (sum == target)
        {
            printf("[Found] %d + %d = %d.\n", a[i], a[j], target);
            return 1;
        }
        else if (sum < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    printf("[Failed] Sum two be %d is not exists.\n", target);
    return 0;
}

int main(int argc, char const *argv[])
{

    int n = 10;
    int *a = malloc(sizeof(int) * n);
    initArrayWithOrder(a, n);
    printArray(a, n);
    twoSum(a, n, 5);
    twoSum(a, n, 19);
    twoSum(a, n, 20);
    return 0;
}
