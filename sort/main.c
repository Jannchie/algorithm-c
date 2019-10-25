#include "sort.h"
#include "util.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int len = 10000;
    int times = 10;
    printf("========== TEST START ==========\n");
    runSort(selectSort, len, times);
    runSort(bubbleSort, len, times);
    runSort(insertSort, len, times);
    printf("==========  TEST END  ==========\n");

    return 0;
}