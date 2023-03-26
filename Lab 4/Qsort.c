#include <stdio.h>
#include <stdlib.h>

void merge(int arr[],int l,int r)
{
    int mid = (l+r)/2;

    int l1 = mid-l+1;
    int l2 = r-mid;

    int left[l1];
    int right[l2];

    int k=l;

    for(int i=0;i<l1;i++)
    {
        left[i]=arr[k++];
    }
    k=mid+1;
    for(int i=0;i<l2;i++)
    {
        right[i]=arr[k++];
    }

    int i = 0;
    int j= 0;
    k=l;
    while(i<l1 && j<l2)
    {
        if(left[i]<right[j])
        {
            arr[k++]=left[i++];
        }
        else
        {
            arr[k++]=right[j++];
        }
    }

    while(i<l1)
    {
        arr[k++]=left[i++];
    }
    while(j<l2)
    {
        arr[k++]=right[j++];
    }
}

void merge_sort(int arr[],int l,int r)
{
    if(l<r)
    {   
        int mid = (l+r)/2;
        merge_sort(arr,0,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,r);
    }
}

// int cmpfunc(const void *a, const void *b)
// {
//     return (*(int *)a - *(int *)b);
// }

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    merge_sort(arr,0,n-1);

    printf("\nAfter sorting the list is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return (0);
}

