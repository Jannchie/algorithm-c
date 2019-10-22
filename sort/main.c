#include "sort.h"
#include "util.h"
int main(int argc, char const *argv[])
{
    int len = 5000;
    int a[len];

    getRandomArray(a, len);

    bubbleSort(a, len);
    // printArray(a, len);
    isAsc(a, len);
    return 0;
}
