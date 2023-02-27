#include<stdio.h>

int main()
{
    int n,k,t;
    scanf("%d %d %d",&n,&k,&t);

    int arr[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    if(n<k)
    {
        printf("invalid");
        return 0;
    }

    int sum = 0;
    int count=0;

    for(int i=0;i<k;i++)
    {
        sum +=arr[i];
    }

    if((sum/k)>=t)
    count++;
    int windowSum = sum;

    for(int i=k;i<n;i++)
    {
        windowSum +=arr[i]-arr[i-k];
        if((windowSum/k)>=t)
        {
            count++;
        }
    }
    
    printf("%d",count);
}