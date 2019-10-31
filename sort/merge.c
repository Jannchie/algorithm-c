void merge(int a[], int left, int mid, int right, int p[])
{
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right)
    {
        p[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
    }
    while (i <= mid)
    {
        p[k++] = a[i++];
    }
    while (j <= right)
    {
        p[k++] = a[j++];
    }
    for (i = 0; i < k; i++)
    {
        a[left + i] = p[i];
    }
}
void mergeR(int a[], int left, int right, int p[])
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeR(a, left, mid, p);
        mergeR(a, mid + 1, right, p);
        merge(a, left, mid, right, p);
    }
}
void mergeSort(int a[], int len)
{
    int p[len];
    mergeR(a, 0, len - 1, p);
}