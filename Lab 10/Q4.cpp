#include<bits/stdc++.h>
using namespace std;

void flip(int arr[],int i)
{
    int temp,start=0;

    while(start<i)
    {
        temp=arr[start];
        arr[start]=arr[i];
        arr[i]=temp;
        start++;
        i--;
    }
}

int maxi(int arr[],int n)
{
    int mi=0,i;

    for(i=0;i<n;i++)
    {
        if(arr[i]>arr[mi])
        mi=i;
    }
    return mi;
}
int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int count=0;
    for(int i=n;i>1;i--)
    {
        int maxindex=maxi(arr,i);

        if(maxindex != i-1)
        {
            flip(arr,maxindex);
            flip(arr,i-1);
            count++;
        }
    }

    cout<<count<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" "; 
    }
    return 0;
}