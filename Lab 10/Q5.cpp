//Striver
#include<bits/stdc++.h>
using namespace std;

static bool comp(pair<int,int>a,pair<int,int>b)
{
    if(a.first==b.first)
    return a.second>b.second;
    
    return a.first<b.first;
}

int main()
{
    int n;
    cin>>n;

    pair<int,int> arr[n];

    for(int i=0;i<n;i++)
    {
        pair<int,int>temp;
        cin>>temp.first;
        cin>>temp.second;
        arr[i]=temp;
    }

    sort(arr,arr+n,comp);

    vector<int> temp;
    temp.push_back(arr[0].second);

    for(int i=1;i<n;i++)
    {
        if(lower_bound(temp.begin(),temp.end(),arr[i].second)!=temp.end())
        {
            temp[lower_bound(temp.begin(),temp.end(),arr[i].second)-temp.begin()] =arr[i].second;
        }
        else
        {
            temp.push_back(arr[i].second);
        }
    }

    cout<<temp.size();

    // int ans=1;

    // int w=arr[0].first;
    // int h=arr[0].second;

    // for(int i=1;i<n;i++)
    // {
    //     int wnext=arr[i].first;
    //     int hnext=arr[i].second;

    //     if(w<wnext && h<hnext)
    //     {
    //         ans++;
    //         w=wnext;
    //         h=hnext;
    //     }
    // }

    // cout<<ans;
    return 0;
}