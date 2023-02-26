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

    for(int i=0;i<n;i++)
    {
        arr[i]=arr[i]%k;
    }

    int freq[k];
    
    for(int i=0;i<k;i++)
    {
        freq[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        freq[arr[i]]++;
    }

    int ans=0;
    ans= ans+freq[0];

    for(int i=0;i<k;i++)
    {
        ans=ans+freq[i]*(freq[i]-1)/2;
    }

    printf("%d",ans);

}