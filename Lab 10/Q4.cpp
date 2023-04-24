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

    vector<int> res;

    for(int i=n;i>1;i--)
    {
        int maxindex=maxi(arr,i);

        if(maxindex != i-1)
        {
            if(maxindex!=0)
            {
                res.push_back(maxindex);
                flip(arr,maxindex);
            }

            res.push_back(i-1);
            flip(arr,i-1);
        }
    }

    cout<<res.size()<<endl; 

    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]+1<<" "; 
    }
    return 0;
}