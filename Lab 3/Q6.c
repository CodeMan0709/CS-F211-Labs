#include <stdio.h>
#include <stdbool.h>

// int count;
// void uniqueEle(int arr[],int start,int end,bool isdup)
// {
//     if(arr[start]==arr[end])
//     {
//         if(isdup==false)
//         count++;
//     }
//     else
//     {
//         int mid = start+(end-start)/2;
//         uniqueEle(arr,start,mid,isdup);
//         uniqueEle(arr,mid+1,end,arr[mid]==arr[mid+1]);
//     }
// }

// int unique(int arr[],int n)
// {
//     uniqueEle(arr,0,n-1,0);
//     return count;
// }
int nextIndex(int arr[], int N, int l, int target)
{
    int result = -1;
    int r = N - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
        {
            result = mid;
            l = mid + 1;
        }
        else if (arr[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }

    return result + 1;
}

int unique(int arr[], int N)
{
    int i = 0;
    int count = 0;
    while (i < N)
    {
        i = nextIndex(arr, N, i, arr[i]);
        count++;
    }
    return count;
}

int main()
{
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    int ans = unique(arr, N);
    printf("%d", ans);
}