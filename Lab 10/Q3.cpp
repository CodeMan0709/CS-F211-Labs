//Striver
#include<bits/stdc++.h>
using namespace std;

float solve(int arr[],int brr[],int a,int b)
{
    int low=0;
    int high=a;

    while(low<=high)
    {
        int cut1 = (low+high)/2;
        int cut2 = (a+b+1)/2 - cut1;

        int left1,left2,right1,right2;

        if(cut1==0)
        left1=INT_MIN;
        else
        left1=arr[cut1-1];

        if(cut2==0)
        left2=INT_MIN;
        else
        left2=brr[cut2-1];

        if(cut1==a)
        right1=INT_MAX;
        else
        right1=arr[cut1];

        if(cut2==b)
        right2=INT_MAX;
        else
        right2=brr[cut2];

        if(left1 <= right2 && left2 <= right1)
        {
            if((a+b)%2 ==0)
            return (max(left1,left2)+min(right1,right2))/2.0;
            else
            return max(left1,left2);
        }
        else if(left1>right2)
        {
            high=cut1-1;
        }
        else
        {
            low=cut1+1;
        }
    }

    return 0.0;

}
int main()
{
    int a;
    cin>>a;

    int arr[a];

    for(int i=0;i<a;i++)
    {
        cin>>arr[i];
    }

    int b;
    cin>>b;

    int brr[b];

    for(int i=0;i<b;i++)
    {
        cin>>brr[i];
    }

    float ans;

    if(a<b)
    ans=solve(arr,brr,a,b);
    else
    ans=solve(brr,arr,b,a);

    cout<<ans;
    
    return 0;
}