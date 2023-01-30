#include <stdio.h>

int main() {

int r1,c1;
scanf("%d %d",&r1,&c1);
 int arr1[r1][c1];
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            scanf("%d",&arr1[i][j]);
        }
    }
    int r2,c2;

scanf("%d %d",&r2,&c2);
    int arr2[r2][c2];
    for(int i=0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
        {
            scanf("%d",&arr2[i][j]);
        }
    }
   
  
    int k1=0;
    int arr1_hor[r1*c1];
     for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            arr1_hor[k1]=arr1[i][j];
            k1++;
        }
    }
    
    int k2=0;
    int arr1_ver[r1*c1];
     for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            arr1_ver[k2]=arr1[j][i];
            k2++;
        }
    }
     int counter_hor=0; int c=0,xx=0;
        
        for(int k=0;k<r1*c1;k+=r2)
            {
                 for(int i=0;i<r2;i++)
                    {
                      for(int j=0;j<c2;j++)
                      {
                        while(c<c2)
                        {
                            if(arr2[i][j+c]==arr1_hor[k+c])
                            {
                                ++c;
                            }
                            else
                            {
                                break;
                            }
                        }
                          if(c==c2)
                            {  
                                counter_hor++;
                            }
                            c=0;
                            }  
                     }
                    }
          
          int counter_ver=0; int cou=0;
        
        for(int k=0;k<r1*c1;k+=c2)
            {
                 for(int i=0;i<r2;i++)
                    {
                      for(int j=0;j<c2;j++)
                      {
                        while(c<c2)
                        {
                            if(arr2[i+cou][j]==arr1_ver[k+cou])
                            {
                                ++cou;
                            }
                            else
                            {
                                break;
                            }
                        }
                          if(cou==c2)
                            {  
                                counter_ver++;
                            }
                            cou=0;
                            }  
                     }
                    }

            if((counter_hor>0 && counter_hor<c2) || (counter_ver>0 && counter_ver<r2))
            {
                printf("Partial");
            }
            if(counter_hor==0 && counter_ver==0)
            {
                printf("NO");
            }
            if(counter_hor==c2 && counter_ver==r2)
            {
                printf("Yes");
            }


    return 0;
}