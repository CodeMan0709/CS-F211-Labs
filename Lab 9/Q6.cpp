#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    map<int,int> mp;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        mp[arr[i]]=0;
    }

    int ans=0;
    for(int i=0;i<n;i++)
    {
        auto it = mp.upper_bound(arr[i]+k-1);

        if(it!=mp.end())
        {
            mp.erase(it);
            ans++;
        }
    }
    cout<<ans;
}