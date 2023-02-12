#include<stdio.h>

int main()
{
    int k,n;
    scanf("%d %d",&k,&n);

    int arr[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int mid=(1+k)/2;

    for(int i=0;i<n;i++)
    {
        if(arr[i]<mid)
        printf("%d ",arr[i]);
    }

    printf("%d ",mid);

    for(int i=0;i<n;i++)
    {
        if(arr[i]>mid)
        printf("%d ",arr[i]);
    }

}
#include <stdio.h>

int main(){
    int n,k;
    scanf("%d %d",&k,&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int mid=(k+1)/2;
    int i=0;
    int midpos;
    int cnt=0;
    while(cnt!=n){
        if(arr[i]>mid){
            for(int j=i;j<n-1;j++){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        else if(arr[i]<mid){
            i++;
        }
        else{
            midpos=i;
            i++;
        }
        cnt++;
    }
    for(int k=midpos;k<(i-1);k++){
        int temp = arr[k];
        arr[k]=arr[k+1];
        arr[k+1]=temp;
    }

    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
}