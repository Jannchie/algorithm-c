/**
 * 东工大 2020
 */
#include "util.h"
int merge(int a[], int begin, int end, int w[])
{
    int mid = (begin + end) / 2;
    int i = begin, j = mid + 1, k, c = 0;
    printf("( %d, %d )\n", begin, end);
    if (begin < end)
    {
        c = merge(a, begin, mid, w);
        c = merge(a, mid + 1, end, w);
        for (k = begin; k <= end; ++k)
        {
            if (mid < i)
            {
                w[k] = a[j++];
            }
            else if (end < j)
            {
                w[k] = a[i++];
            }
            else
            {
                c += 1;
                if (a[i] < a[j])
                {
                    w[k] = a[i++];
                }
                else
                {
                    w[k] = a[j++];
                }
            }
        }
        for (k = begin; k <= end; ++k)
        {
            a[k] = w[k];
        }
    }
    return c;
}

int mergesort(int arr[], int len)
{
    int *temp = (int *)malloc(sizeof(int) * len);
    return merge(arr, 0, len - 1, temp);
}
int main(int argc, char const *argv[])
{
    int n = 5;
    int a[] = {6, 5, 3, 1, 4};
    int c = mergesort(a, 5);
    printf("count: %d\n", c);
    return 0;
}