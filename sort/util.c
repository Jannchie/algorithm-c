#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int isAsc(int *a, int len)
{
    for (int i = 1; i < len; i++)
    {
        if (a[i - 1] > a[i])
        {
            printf("[ERROR]\t\tNot Sort By Asc\n");
            printArray(a, len);
            return 0;
        }
    }
    printf("[PASS]\t\tArray Sort By Asc\n");
    return 1;
}

void getRandomArray(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        a[i] = rand();
    }
}
void getSortedArray(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        a[i] = i + 1;
    }
}

void runSort(void (*sortFunction)(int[], int), int len, int times)
{
    // printf("[INFO]\t\t\"%s\" started\n");
    int a[len];

    clock_t start, end;
    start = clock();

    while (times--)
    {
        getRandomArray(a, len);
        // 执行排序算法
        sortFunction(a, len);
    }

    end = clock();
    printf("[INFO]\t\tused time = %3f\n", (double)(end - start) / CLOCKS_PER_SEC);
    isAsc(a, len);
}