//GFG
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
#define pi pair<int,int>

int main()
{
    int n;
    cin>>n;
    pi arr[n];

    for(int i=0;i<n;i++)
    {
        pi temp;
        cin>>temp.first;
        cin>>temp.second;
        arr[i]=temp;
    }

    map<pi,int>mp;
    int ans=0;

    for(int i=0;i<n;i++)
    {
        mp.clear();
        for(int j=i+1;j<n;j++)
        {
            int x = arr[i].first-arr[j].first;
            int y = arr[i].second-arr[j].second;
            int g = __gcd(x,y);
            x=x/g;
            y=y/g;
            mp[{x,y}]++;
        }

        int remNo = n-(i+1);
        ans += remNo*(remNo-1)/2;

        for(auto j:mp)
        {
            ans -= j.second*(j.second-1)/2;
        }
    }

    cout<<ans<<endl;
}