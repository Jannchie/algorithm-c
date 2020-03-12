#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a[] = {0, 1, 2, 3};
    int i = 0;
    a[i++] = 100;
    printf("%d ", i);
    printf("%d ", a[i - 1]);
    return 0;
}
