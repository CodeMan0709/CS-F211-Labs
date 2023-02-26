#include<stdio.h>
// #define int long long;

int count = 0;

void paraSolver(int n,char arr[],int open,int close,int itr)
{
    if(itr==n)
    {
        printf("%s\n",arr);
        count++;
        return;
    }

    if(open<n/2)
    {
        arr[itr] = '(';
        paraSolver(n,arr,open+1,close,itr+1);
    }

    if(close<open)
    {
        arr[itr] = ')';
        paraSolver(n,arr,open,close+1,itr+1);
    }
}

int main()
{
    int n;
    scanf("%d",&n);

    char arr[n+1];
    arr[n]='\0';

    paraSolver(n,arr,0,0,0);

    printf("%d",count);


}