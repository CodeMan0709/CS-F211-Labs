#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    int i=0;

    int count = 0;
    while(count!=n)
    {
        if(arr[i]>0)
        {
            for(int j=i;j<n-1;j++)
            {
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        
        else if(arr[i]<0)
        i++;
        
        count++;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}    