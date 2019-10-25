#include "util.h"
#include <stdio.h>
/**
 * @name: 冒泡排序
 * @author: Jannchie
 * @date: 2019-10-22
 * */
void bubbleSort(int a[], int len)
{
    int c = 0;
    // i为每轮冒泡的目标位置
    for (int i = len; i > 0; i--)
    {
        // 从第2个元素开始比较
        for (int j = 1; j < i; j++)
        {
            c += 1;
            // 如果该元素比前一个元素小
            if (a[j] < a[j - 1])
            {
                //则将前一个元素网上冒泡
                swap(&a[j - 1], &a[j]);
            }
        }
    }
    printf("%d", c);
}

/**
 * @name: 强化冒泡排序
 * @author: Jannchie
 * @date: 2019-10-22
 * @desc: 这种排序在原数组接近有序时，速度非常快。
 * */
void optimized_bubbleSort(int a[], int len)
{
    int c = 0;
    int last = len;
    while (last)
    {
        int i = last;
        last = 0;
        for (int j = 1; j <= i; j++)
        {
            c += 1;
            if (a[j - 1] > a[j])
            {
                last = j;
                swap(&a[j - 1], &a[j]);
            }
        }
    }
    printf("%d", c);
}