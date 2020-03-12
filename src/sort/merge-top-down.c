#include "util.h"

// 迭代法（Bottom-up）
void mergeSortBottomUp(int arr[], int len)
{
    int *a = arr;
    int *b = (int *)malloc(len * sizeof(int));
    for (int seg = 1; seg < len; seg *= 2)
    {
        for (int start = 0; start < len; start += seg * 2)
        {
            int mid = start + seg < len ? start + seg : len;
            int end = start + seg * 2 < len ? start + seg * 2 : len;
            int start1 = start, end1 = mid;
            int start2 = mid, end2 = end;
            int index = start;
            while (start1 < end1 && start2 < end2)
            {
                b[index++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            }
            while (start1 < end1)
            {
                b[index++] = a[start1++];
            }
            while (start2 < end2)
            {
                b[index++] = a[start2++];
            }
        }
        int *temp = a;
        a = b;
        b = temp;
    }
    free(b);
}

int main(int argc, char const *argv[])
{
    int n = 10000;
    int times = 1000;
    runSort("merge sort", mergeSortBottomUp, n, times);
    return 0;
}