#include "util.h"
void shell_sort(int a[], int n)
{
    int i, j, k;
    int temp;
    for (k = n / 2; k > 0; k /= 2)
    {
        for (i = k; i < n; i++)
        {
            for (j = i; j > k && temp < a[j - k]; j -= k)
            {
                a[j] = a[j - k];
            }
            a[j] = temp;
        }
    }
}

int main(int argc, char const *argv[])
{
    int n = 1000;
    int times = 1000;
    runSort("shell sort", shell_sort, n, times);
    return 0;
}