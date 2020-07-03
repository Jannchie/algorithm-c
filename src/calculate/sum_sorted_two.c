int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
    *returnSize = 2;
    int i = 0;
    int j = numbersSize - 1;
    while (i < j)
    {
        int sum = numbers[i] + numbers[j];
        if (sum == target)
        {
            int *a = (int *)malloc(sizeof(int) * 2);
            a[0] = i + 1;
            a[1] = j + 1;
            return a;
        }
        sum < target ? i++ : j--;
    }
    return -1;
}