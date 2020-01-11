#include "util.h"
void selectSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}
int main(int argc, char const *argv[])
{
    int n = 1000;
    int times = 1000;
    runSort("select sort", selectSort, n, times);
    return 0;
}