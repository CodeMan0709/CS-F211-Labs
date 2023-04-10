#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    map<int,int> mp;
    pair<int,int> arr[n];

    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        arr[i]={x,y};
    }

    for(int i=0;i<n;i++)
    {
        mp[arr[i].first]+=0;
        mp[arr[i].second]++;
    }

    for(auto it:mp)
    {
        if(it.second<=1)
        cout<<it.first<<" ";
    }

}