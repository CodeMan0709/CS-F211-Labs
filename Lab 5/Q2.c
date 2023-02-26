#include<stdio.h>

long long int findPos(long long int n,int flag)
{
    if(n==1)
    return 1;

    if(flag == 1)
    {
        return 2*(findPos(n/2,0));
    }

    if(n%2==0)
    {
        return (2*(findPos((n+1)/2,1))) - 1;
    }

    return 2* (findPos(n/2,1));
    
}

int main()
{
    long long int n;
    scanf("%lld",&n);

    long long int ans = findPos(n,1);
    printf("%lld",ans);
    
}