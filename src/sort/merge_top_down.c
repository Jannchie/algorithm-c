#include "util.h"
// 递归法（Top-down)
void mergeSortRecursive(int arr[], int temp[], int start, int end)
{
    if (start >= end)
        return;
    int mid = (end - start) / 2 + start;
    mergeSortRecursive(arr, temp, start, mid);
    mergeSortRecursive(arr, temp, mid + 1, end);
    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end)
    {
        temp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }
    for (i = 0; i < k; i++)
    {
        arr[start + i] = temp[i];
    }
}

void mergeSortTopDown(int arr[], int len)
{
    int *temp = (int *)malloc(sizeof(int) * len);
    // int temp[len];
    mergeSortRecursive(arr, temp, 0, len - 1);
}
int main(int argc, char const *argv[])
{
    int n = 10000;
    int times = 1000;
    runSort("merge sort", mergeSortTopDown, n, times);
    return 0;
}