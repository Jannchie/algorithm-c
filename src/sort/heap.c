#include "util.h"
// 非递归
void maxHeapify2(int arr[], int start, int end)
{
  int rootIndex = start;
  int childIndex = rootIndex * 2 + 1;
  while (childIndex <= end) // 有左儿子，才可能产生交换
  {
    // 找较大的儿子
    if (childIndex + 1 <= end && arr[childIndex + 1] > arr[childIndex])
    {
      childIndex++;
    }
    // 较大的儿子如果比父亲大，则交换
    if (arr[rootIndex] < arr[childIndex])
    {
      swap(&arr[rootIndex], &arr[childIndex]);
      // 交换后儿子可能不满足堆，需要调整儿子
      rootIndex = childIndex;
      childIndex = rootIndex * 2 + 1;
    }
    else // 如果无需调整，则调整完毕
    {
      return;
    }
  }
}
// 递归
void maxHeapify(int arr[], int start, int end)
{
  int rootIndex = start;
  int childIndex = rootIndex * 2 + 1;
  if (childIndex <= end) // 有左儿子，才可能产生交换
  {
    // 有右儿子，则找较大的儿子
    if (childIndex + 1 <= end && arr[childIndex + 1] > arr[childIndex])
    {
      childIndex++;
    }
    // 较大的儿子如果比父亲大，则交换
    if (arr[rootIndex] < arr[childIndex])
    {
      swap(&arr[rootIndex], &arr[childIndex]);
      printArray(arr, 10);
      // 交换后儿子可能不满足堆，需要调整儿子
      maxHeapify(arr, childIndex, end);
    }
  }
}

void heapSort(int arr[], int len)
{
  int i;
  // 初始化堆，最后一层不用考虑：len / 2
  for (i = len / 2 - 1; i >= 0; i--)
  {
    maxHeapify(arr, i, len - 1);
  }
  // 交换最后一个，堆-1，并调整堆
  for (i = len - 1; i > 0; i--)
  {
    swap(&arr[i], &arr[0]);
    maxHeapify(arr, 0, i - 1);
  }
}

int main()
{
  int n = 10;
  int times = 1;
  runSort("heap sort", heapSort, n, times);
  return 0;
}