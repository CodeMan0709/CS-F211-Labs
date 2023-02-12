#include <stdio.h>
#include <stdlib.h>

int occ(int arr[], int n, int ele)
{
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        counter = counter + arr[i] / ele;
    }

    return counter;
}

int main()
{
    int n,k;
    
    scanf("%d %d", &n, &k);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int maxno=-1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxno)
        maxno = arr[i];
    }

    int left = 0;
    int right = maxno;
    int mid = (left+right)/2;
    int ans=0;

    while(left<=right)
    {
        if(mid==0)
        break;

        if(occ(arr,n,mid)>=k)
        {
            ans = mid;
            left=mid+1;
        }
        
        else
        {
            right=mid-1;
        }
        mid = (left+right)/2;
    }
    printf("%d",ans);
}    