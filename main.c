#include "sort/sort.h"
#include "sort/util.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int len = 10000;
    int times = 500;
    printf("============== TEST START ==============\n");
    runSort("Select Sort", selectSort, len, times);
    runSort("Bubble Sort", bubbleSort, len, times);
    runSort("Insert Sort", insertSort, len, times);
    runSort("Quick  Sort", quickSort, len, times);
    printf("==============  TEST END  ==============\n");
    return 0;
}
