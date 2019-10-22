/**
 * @name: 选择排序
 * @author: Jannchie
 * 
 * */

#include "util.h"

void selectSort(int *a, int len)
{

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (a[i] > a[j])
            {
                swap(&a[i], &a[j]);
            }
        }
    }
}
