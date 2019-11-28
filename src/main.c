#include "sort/sort.h"
#include "sort/util.h"
#include "data-structure/linklist.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int len = 10000;
    int times = 10;
    srand(time(0));
    printf("=========== [数据结构 - 开始运行] ===========\n");
    printf("----------- [数    组 - 开始运行] -----------\n");
    printf("----------- [链    表 - 开始运行] -----------\n");
    testLinklist();
    printf("=========== [排序算法 - 开始运行] ===========\n");
    runSort("Heap   Sort", heapSort, len, times);
    runSort("Select Sort", selectSort, len, times);
    runSort("Bubble Sort", bubbleSort, len, times);
    runSort("Insert Sort", insertSort, len, times);
    runSort("Quick  Sort", quickSort, len, times);
    runSort("Quick3 Sort", quickSortMidian3, len, times);
    runSort("Merge  Sort", mergeSort, len, times);
    printf("=========== [排序算法 - 运行结束] ===========\n");
    return 0;
}