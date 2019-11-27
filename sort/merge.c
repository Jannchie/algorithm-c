/**
 * @name: 归并排序 - 归并方法
 * @author: Jannchie
 * @date: 2019-10-31
 * */
void merge(int a[], int left, int mid, int right, int temp[])
{
    int i = left;
    int j = mid + 1;
    int k = 0;
    // 如果两边都还有元素
    while (i <= mid && j <= right)
    {
        // 取较小的存放到temp中
        temp[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
    }
    // 如果分别还有元素，则全部装入temp中
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= right)
    {
        temp[k++] = a[j++];
    }

    // 将temp中的元素输出到原数组的相应位置
    for (i = 0; i < k; i++)
    {
        a[left + i] = temp[i];
    }
}
/**
 * @name: 归并排序 - 递归函数
 * @author: Jannchie
 * @date: 2019-10-31
 * */
void divideAndMerge(int a[], int left, int right, int temp[])
{
    // 终止条件为 left = right, 此时没有必要再分割了。
    // 如果 left < right 说明初始数组为空。
    if (left < right)
    {
        // 对半分治
        int mid = (left + right) / 2;
        divideAndMerge(a, left, mid, temp);
        divideAndMerge(a, mid + 1, right, temp);
        merge(a, left, mid, right, temp);
    }
}
/**
 * @name: 归并排序 - 递归实现
 * @author: Jannchie
 * @date: 2019-10-31
 * */
void mergeSort(int a[], int len)
{
    // 开辟临时空间
    int temp[len];
    divideAndMerge(a, 0, len - 1, temp);
}