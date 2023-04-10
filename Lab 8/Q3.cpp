// Divyas Code
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int x,y;
    cin>>x>>y;

    int yrr[n];
    for(int j=0;j<n;j++)
    {
        yrr[j] = arr[j] - y*j;
    }

    int xrr[n];
    for(int i=0;i<n;i++)
    {
        xrr[i]=arr[i]-x*i;
    }

    int answer=0;

    map<int,int>mp;

    for(auto x:yrr)
    {
        mp[x]++;
    }
    for(int i=0;i<n;i++)
    {
        mp[yrr[i]]--;
        answer+=mp[xrr[i]];
    }

    cout<<answer<<endl;
}