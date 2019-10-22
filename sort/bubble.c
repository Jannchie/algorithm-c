/**
 * @name: 冒泡排序
 * @author: Jannchie
 * @date: 2019-10-22
 * */

#include "util.h"

void bubbleSort(int a[], int len)
{
    // i为每轮冒泡的目标位置
    for (int i = len; i > 0; i--)
    {
        // 从第2个元素开始比较
        for (int j = 1; j < i; j++)
        {
            // 如果该元素比前一个元素小
            if (a[j] < a[j - 1])
            {
                //则将前一个元素网上冒泡
                swap(&a[j - 1], &a[j]);
            }
        }
    }
}