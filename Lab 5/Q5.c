#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // int start = 0;
    // int end = k;
    // int window = 0;
    // int ans = 0;
    // while (start < n)
    // {
    //     int temp = start;
    //     while (end >= 0 && temp < n)
    //     {
    //         if (arr[temp] == 0)
    //         {
    //             end--;
    //             if (end == -1)
    //             {
    //                 break;
    //             }
    //         }
    //         window++;
    //         temp++;
    //     }
    //     end = k;
    //     ans = max(ans, window);
    //     window = 0;
    //     start++;
    // }
    // printf("%d", ans);

    int i = 0;
    int j = 0;
    int count = 0;
    int window = 0;
    int ans = 0;

    if (arr[0] == 0)
    {
        count++;
    }

    while (j < n)
    {
        if (count > k)
        {
            if (arr[i] == 0)
            {
                count--;
            }
            i++;

            continue;
        }
        
        window = j - i + 1;
        ans = max(ans, window);
        j++;

        if (j == n)
        {
            break;
        }

        if (arr[j] == 0)
        {
            count++;
        }
    }

    printf("%d", ans);
}