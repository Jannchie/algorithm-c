#include "util.h"
void sort(int arr[], int first, int last)
{
    if (first > last)
        return;
    int i = first, j = last;
    int pivot = arr[i];
    while (i < j)
    {
        while (i < j && arr[j] > pivot)
        {
            j--;
        }
        arr[i] = arr[j];
        while (i < j && arr[i] < pivot)
        {
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    sort(arr, first, i - 1);
    sort(arr, i + 1, last);
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