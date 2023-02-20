#include<stdio.h>
#include<stdbool.h>
bool isPrime(int x)
{
    if(x==1)
    return false;

    if(x==2 || x==3)
    return true;

    if(x%2==0 || x%3==0)
    return false;

    for(int i=5;i*i<=x;i=i+6)
    {
        if(x%i==0 || x%(i+2)==0)
        return false;
    }

    return true;
}

int main()
{
    int n,q;
    scanf("%d %d",&n,&q);

    int arr[n+1];

    for(int i=0;i<n+1;i++)
    {
        arr[i]=0;
    }

    for(int i=0;i<n+1;i++)
    {
        if(isPrime(i))
        {
            arr[i]=1;
        }
    }
    
    for(int i=1;i<n+1;i++)
    {
        arr[i]=arr[i]+arr[i-1];
    }

    for(int i=0;i<q;i++)
    {
        int x;
        scanf("%d",&x);

        int count = 0;

        count = arr[x];
        
        printf("%d ",count);  
        
    }
}