#include <stdio.h>
#include <stdlib.h>

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
            printf("[ERROR]\t\t Not Sort By Asc\n");
            return 0;
        }
    }
    printf("[PASS]\t\t Array Sort By Asc\n");
    return 1;
}

void getRandomArray(int *a, int len)
{
    printf("[START]\t\t Creating Random Array\n");
    for (int i = 0; i < len; i++)
    {
        a[i] = rand();
    }
    printf("[OK]\t\t Created Random Array\n");
}