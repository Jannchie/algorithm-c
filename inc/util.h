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

void initArrayWithOrder(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        a[i] = i + 1;
    }
}
/**
 * 费空间
 */
void randomArray(int *a, int len)
{
    initArrayWithOrder(a, len);
    for (int i = 0; i < len; i++)
    {
        a[i] = rand();
    }
}

void shuffle(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        int j = rand() % (len - i);
        swap(&a[i], &a[i + j]);
    }
}

int *getShuffledArray(int len)
{
    int *a = (int *)malloc(sizeof(int) * len);
    initArrayWithOrder(a, len);
    shuffle(a, len);
    return a;
}

void runSort(char const name[], void (*sortFunction)(int[], int), int len, int times)
{

    clock_t start, end;
    int result = 1;
    start = clock();
    while (times--)
    {
        int *a = getShuffledArray(len);
        if (len < 20 && times == 0)
        {
            printf("排序前：");
            printArray(a, len);
        }
        // 执行排序算法
        sortFunction(a, len);
        if (len < 20 && times == 0)
        {
            printf("排序后：");
            printArray(a, len);
        }
        if (!isAsc(a, len))
        {
            result = 0;
        };
    }

    end = clock();
    char state[20] = "";
    strcpy(state, result ? "\033[0;32m[ √ ]\033[0m" : "\033[0;31m[ × ]\033[0m");

    printf("[%s]\tUSED TIME = %fs\t%s\n", name, (double)(end - start) / CLOCKS_PER_SEC, state);
}