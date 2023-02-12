#include<stdio.h>
#include<string.h>

int main()
{
    char s1[1000];
    char s2[1000];
    gets(s1);
    gets(s2);

    int a = strlen(s1);
    int b= strlen(s2);

    if(a!=b)
    {
    printf("Not Pussible");
    return 0;
    }

    int check[a];

    for(int i=0;i<a;i++)
    {
        check[i]=0;
    }

    int arr[a];

    for(int i=0;i<a;i++)
    {
        arr[i]=0;
    }

    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(s2[i]==s1[j] && check[j]==0)
            {
            arr[i]=j+1;
            check[j]=1;
            break;
            }
        }
        if(arr[i]==0)
        {
        printf("Not Poble");
        return 0;
        }
    }

    for(int i=0;i<a;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;

}