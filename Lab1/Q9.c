#include<stdio.h>

int main()
{
    int k,n;
    scanf("%d %d",&k,&n);

    int arr[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int mid=(1+k)/2;

    for(int i=0;i<n;i++)
    {
        if(arr[i]<mid)
        printf("%d ",arr[i]);
    }

    printf("%d ",mid);

    for(int i=0;i<n;i++)
    {
        if(arr[i]>mid)
        printf("%d ",arr[i]);
    }

}