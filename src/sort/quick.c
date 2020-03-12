#include "util.h"
void sort(int arr[], int l, int r)
{
    if(l > r)
        return;
    int i = l, j = r;
    int pivot = arr[i];
    while (i < j)
    {
        while (i < j && arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            arr[i++] = arr[j];
        }
        while (i < j && arr[i] < pivot)
        {
            i++;
        }
        if (i < j)
        {
            arr[j--] = arr[i];
        }
    }
    arr[i] = pivot;
    sort(arr, l, i - 1);
    sort(arr, i + 1, r);
}

void quickSort(int arr[], int n)
{
    sort(arr, 0, n - 1);
}

int main(int argc, char const *argv[])
{
    int n = 1000;
    int times = 1000;
    runSort("quick sort", quickSort, n, times);
    return 0;
}