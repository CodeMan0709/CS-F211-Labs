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

    int start=0;
    int end=k-1;
    int count=0;
    while(start<end && start<=n-k)
    {
        int sum = 0 ;
        int temp = start;
        while(temp<=end)
        {
            sum=sum+arr[temp];
            temp++;
        }
        int avg = sum/k;

        if(avg>=t)
        count++;

        start++;
        end++;
    }

    printf("%d",count);
}