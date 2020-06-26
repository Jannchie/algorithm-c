#include "util.h"
void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j - 1] > a[j])
            {
                swap(&a[j - 1], &a[j]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n = 1000;
    int times = 1000;
    runSort("bubbleSort", bubbleSort, n, times);
    return 0;
}