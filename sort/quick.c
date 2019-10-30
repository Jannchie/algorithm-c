
/**
 * @name: 快速排序 - 递归调用
 * @author: Jannchie
 * @date: 2019-10-30
 * */
void qSort(int a[], int left, int right)
{
    if (left < right)
    {
        int i = left, j = right;
        int pivot = a[i];
        while (i < j)
        {

            while (i < j && a[j] > pivot)
            {
                j--;
            }
            if (i < j)
            {
                a[i++] = a[j];
            }
            while (i < (j + 1) && a[i] < pivot)
            {
                i++;
            }
            if (i < j)
            {
                a[j--] = a[i];
            }
        }
        a[i] = pivot;
        qSort(a, left, i - 1);
        qSort(a, i + 1, right);
    }
}

/**
 * @name: 快速排序
 * @author: Jannchie
 * @date: 2019-10-30
 * */
void quickSort(int a[], int len)
{
    qSort(a, 0, len - 1);
}