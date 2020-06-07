
#include "util.h"
int *twoSum(int *a, int start, int end, int target)
{
    int *r = malloc(sizeof(int) * 3);
    int i = start;
    int j = end;
    while (i < j)
    {
        int sum = a[i] + a[j];
        if (sum == target)
        {
            r[0] = 1;
            r[1] = a[i];
            r[2] = a[j];
            return r;
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
    r[0] = 0;
    return r;
}
int threeSum(int *a, int len, int target)
{
    for (int z = 0; z < len - 2; z++)
    {
        int twoSumTarget = target - a[z];
        int *result = twoSum(a, z + 1, len - 1, twoSumTarget);
        if (result[0] == 1)
        {
            printf("[Found] %d + %d + %d = %d.\n", a[z], result[1], result[2], target);
            return 1;
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
    threeSum(a, n, 5);
    threeSum(a, n, 19);
    threeSum(a, n, 20);
    return 0;
}
