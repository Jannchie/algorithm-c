#include "util.h"
void bubbleSort(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 1; j--)
        {
            if( arr[j - 1] > arr[j]){
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
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