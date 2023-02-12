#include <stdio.h>
#include<stdlib.h>

int main()
{
    int m,n,p,q;
    scanf("%d %d",&m,&n);

    int mux_a [m][n];

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&mux_a[i][j]);
        }
    }

    scanf("%d %d",&p,&q);
    int mux_b [p][q];

    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            scanf("%d",&mux_b[i][j]);
        }
    }
    int row=0;
    int colm=0;
    if(m>=p && n>=q)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                
            }
        }
    }

    

 
}