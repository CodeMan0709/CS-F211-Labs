#include<stdio.h>

int abst(int a,int b)
{
    if(a>b)
    return a-b;
    else
    return b-a;
}

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n];

    int sum =0;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        sum=sum+arr[i];
    }

    if(sum%n != 0)
    {
        printf("all cant get equal chocolate");
        return 0;
    }
    int each = sum/n;

    int op=0;

    for(int i=0;i<n;i++)
    {
        op = op + abst(arr[i],each);
    }
    
    printf("%d",op);
}