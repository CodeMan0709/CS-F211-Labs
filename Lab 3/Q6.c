#include <stdio.h>

int last(int arr[], int low, int high, int x, int n)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if ((mid == n - 1 || x < arr[mid + 1]) && arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            return last(arr, low, (mid - 1), x, n);
        else
            return last(arr, (mid + 1), high, x, n);
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    if(n==0)
    {
        printf("%d",0);
        return 0;
    }
    int arr[n];
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int y = 0;
    int count = 1;

    for (int i = 0; i < n; i++)
    {
        int j = last(arr,i,n-1,arr[i],n);
        i=j+1;
        count++;
    }
    printf("%d", count);
    return 0;
}