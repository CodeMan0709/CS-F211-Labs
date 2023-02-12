#include<stdio.h>

typedef enum{ 
	false = 0, 
	true 
}bool;

bool isPrime(int x)
{
    if(x==1)
    return false;

    if(x==2 || x==3)
    return true;

    if(x%2==0 || x%3==0)
    return false;

    for(int i=5;i*i<=x;i=i+6)  // Pattern in Primes 5,7 11,13 17,19
    {
        if(x%i==0 || x%(i+2)==0)
        return false;
    }

    return true;
}

int main()
{
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    
    long long int arr[b-a+1];

    for(int i=0;i<b-a+1;i++)
    {
        arr[i]=0;
    }
    
    long long int j=0;

    for(long long int i=a;i<=b;i++)
    {
        if(isPrime(i))
        {
            arr[j]=i;
            j++;
        } 
    }

    int arr2[10];
    for(int i=0;i<10;i++)
    {
        arr2[i]=0;
    }
    int r;

    for(int i=0;i<b-a;i++)
    {
        if(arr[i] != 0)
        {
            while(arr[i]!=0)
            {
                r=arr[i]%10;
                arr2[r]++;
                arr[i]=arr[i]/10;
            }
        }
    }

    int max=arr2[0];
    int k=-1;
    for(int i=0;i<10;i++)
    {
        if(max<arr2[i])
        {
            max=arr2[i];
            k=i;
        }
          
    }

    printf("%d %d",k,max);
    
}