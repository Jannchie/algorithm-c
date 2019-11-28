#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
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
            return 0;
        }
    }
    return 1;
}

void getRandomArray(int *a, int len)
{
    srand(rand());
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

void runSort(char const name[], void (*sortFunction)(int[], int), int len, int times)
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
    char state[20] = "";
    strcpy(state, isAsc(a, len) ? "\033[0;32m[ √ ]\033[0m" : "\033[0;31m[ × ]\033[0m");

    printf("[%s]\tUSED TIME = %fs\t%s\n", name, (double)(end - start) / CLOCKS_PER_SEC, state);
}