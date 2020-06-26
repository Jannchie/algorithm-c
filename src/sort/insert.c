#include "util.h"
void insert_sort_1(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = a[i], j;
        for (j = i; j > 0 && a[j - 1] > temp; j--)
        {
            a[j] = a[j - 1];
        }
        a[j] = temp;
    }
}
void insert_sort_2(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = a[i], j = i;
        while (j > 0 && a[j - 1] > temp)
        {
            a[j--] = a[j - 1];
        }
        a[j] = temp;
    }
}
int main(int argc, char const *argv[])
{
    int n = 1000;
    int times = 1000;
    runSort("insert sort", insert_sort_2, n, times);
    return 0;
}