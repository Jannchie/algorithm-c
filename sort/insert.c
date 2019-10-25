#include "util.h"

/**
 * @name: 插入排序
 * @author: Jannchie
 * @date: 2019-10-22
 * */
void insertSort(int a[], int len)
{
    for (int i = 1; i < len; i++)
    {
        if (a[i] < a[i - 1])
        {
            int temp = a[i], j;
            for (j = i - 1; j >= 0 && a[j] > temp; j--)
            {
                a[j + 1] = a[j];
            }
            a[j] = temp;
        }
    }
}
