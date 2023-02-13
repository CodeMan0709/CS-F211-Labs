#include<stdio.h>
#include<stdbool.h>

int count;
void uniqueEle(int arr[],int start,int end,bool isdup)
{
    if(arr[start]==arr[end]){
        if(isdup==false)
        count++;
    }
    else{
        int mid = start+(end-start)/2;
        uniqueEle(arr,start,mid,isdup);
        uniqueEle(arr,mid+1,end,arr[mid]==arr[mid+1]);
    }
}

int unique(int arr[],int n)
{
    uniqueEle(arr,0,n-1,0);
    return count;
}

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int ans = unique(arr, n);
    printf("%d",ans);
}