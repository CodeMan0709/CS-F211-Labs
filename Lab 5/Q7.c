#include<stdio.h>
#include <limits.h>
#include <string.h>

int minimum(int a, int b)
{
    return (a <= b) ? a : b;
}

int maximum(int a, int b)
{
    return (a >= b) ? a : b;
}

int solve(int arr[],int distr[],int n,int k,int curr,int max)
{
    if(curr==n)
    {
        return max;
    }

    int currmin = INT_MAX;

    for(int i=0;i<k;i++)
    {
        distr[i] = distr[i] + arr[curr];
        int temp = solve(arr,distr,n,k,curr+1,maximum(max,distr[i]));
        currmin = minimum(temp,currmin);
        distr[i] -= arr[curr];
    }

    return currmin;

}

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);

    int arr[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int distr[k];

    memset(distr,0,sizeof(distr));

    int ans = solve(arr,distr,n,k,0,0);

    printf("%d",ans);
}