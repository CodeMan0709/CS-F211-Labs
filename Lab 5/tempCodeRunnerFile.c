#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int start = 0;
    int end = 0;
    int count = 0;
    int ans = 0;

    while (end < n)
    {
        if (arr[end] % 2 == 1)
        {
            count++;
        }
        while (count == k)
        {

            ans++;
            if (end + 1 < n && arr[end + 1] % 2 == 0)
            {
                ans++;
                end++;
            }
            if (arr[start] % 2 == 1)
            {
                count--;
            }
            start++;
        }
        end++;
    }

    printf("%d", ans);
}