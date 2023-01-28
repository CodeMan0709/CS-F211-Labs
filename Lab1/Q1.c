#include <stdio.h>
#include<stdlib.h>

int main()
{
    int m,n;
    int ri,ci,rh,ch;
    scanf("%d %d",&m,&n);

    int mux_a [m][n];
    int mux_b [m][n];

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&mux_a[i][j]);
        }
    }

    scanf("%d %d %d %d",&ri,&ci,&rh,&ch);
    int sum=0;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            sum=sum+mux_a[i][j];
            mux_b[i][j]=sum;
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",mux_b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    if(ri+rh>m || ci+ch>n)
    {
    printf("NOT POSSIBLE");
    return 0;
    }
    
    int sum2=0;
    for(int i=ri;i<ri+rh;i++)
    {
        for(int j=ci;j<ch+ci;j++)
        {
            sum2= sum2+mux_b[i][j];
        }
    }
    printf("%d",sum2);
    return 0;
}