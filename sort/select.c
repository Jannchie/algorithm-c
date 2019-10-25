#include "util.h"

/**
 * @name: 选择排序
 * @author: Jannchie
 * @date: 2019-10-22
 * */
void selectSort(int a[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }
        swap(&a[min], &a[i]);
    }
}
