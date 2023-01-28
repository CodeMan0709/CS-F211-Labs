#include<stdio.h>

typedef enum{ 
	false = 0, 
	true 
}bool;

bool isSubsetSum(int set[], int i, int sum,int size,bool arr2[])
{

    if (sum == 0)
        return true;
    if (i == size)
        return false;

    if (set[i] > sum)
        return isSubsetSum(set, i+1, sum,size,arr2);

    if(isSubsetSum(set, i+1, sum,size,arr2))
    {
        return true;
    }
   
    if(isSubsetSum(set, i+1 , sum - set[i],size,arr2)){
        arr2[i]=true;
        return true;
    }
}

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int target;
    scanf("%d",&target);
    
    bool arr2[n];

    for(int i=0;i<n;i++)
    {
        arr2[i]=false;
    }
    bool ans =isSubsetSum(arr,0,target,n,arr2);
    if(ans)
    {
        printf("POSSIBLE \n");
        for(int i=0;i<n;i++)
        {
            if(arr2[i]==true) 
            printf("%d ",arr[i]);
        }
    }
    else
        printf("NOT POSSIBLE");

    return 0;
}