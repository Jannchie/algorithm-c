#include "util.h"
void insertSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            int temp = arr[i],j;
            for (j = i - 1; j > 0 && arr[j] > temp; j--)
            {
                arr[j + 1] = arr[j];
            }
            arr[j] = temp;
        }
    }
}
int main(int argc, char const *argv[])
{
    int n = 1000;
    int times = 1000;
    runSort("insert sort", insertSort, n, times);
    return 0;
}