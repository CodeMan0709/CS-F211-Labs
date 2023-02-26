#include<stdio.h>

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);

    int arr[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=1;i<n;i++)
    {
        arr[i]=arr[i]+arr[i-1];
    }

    int freq[k];
    
    for(int i=0;i<n;i++)
    {
        freq[arr[i]%k]=0;
    }

    for(int i=0;i<n;i++)
    {
        freq[arr[i]%k]++;
    }

    int ans=0;
    ans= ans+freq[0];

    for(int i=0;i<n;i++)
    {
        ans=ans+freq[arr[i]%k]*(freq[arr[i]%k]-1)/2;
        freq[arr[i]%k] =0;
    }

    printf("%d",ans);

}