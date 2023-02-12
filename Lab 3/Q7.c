#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (arr[m] <= x)
            l = m + 1;
        else
            r = m - 1;
    }
    return l;
}

int main()
{
    int n, limit;
    scanf("%d %d", &n, &limit);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int temp = binarySearch(arr, 0, n - 1, limit);
    printf("%d", arr[temp - 1]);
    return 0;
}
