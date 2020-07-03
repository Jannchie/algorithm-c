char *reverseWords(char *s)
{
    int i = 0, j = 0, l, r;
    char temp;
    while (s[j++] != '\0')
    {
        if (s[j] == '\0' || s[j] == ' ')
        {
            l = i, r = j - 1;
            while (l < r)
            {
                temp = s[l];
                s[l++] = s[r];
                s[r--] = temp;
            }
            i = j + 1;
        }
    }
    return s;
}
int main(int argc, char const *argv[])
{
    printf("%d", -3 % 12);
    return 0;
}
