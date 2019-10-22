#include "sort.h"
#include "util.h"
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int len = 50000;
    int a[len];
    for (int i = 0; i < len; i++)
    {
        a[i] = rand();
    }

    bubbleSort(a, len);
    // printArray(a, len);
    return 0;
}
