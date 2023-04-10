#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    vector<string> words;

    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        words.push_back(temp);
    }

    map<string,int>mp;

    for(int i=0;i<n;i++)
    {
        string temp = words[i];
        sort(begin(temp),end(temp));
        mp[temp]++;
    }

    int ans = 0;

    for(auto it:mp)
    {
        int a = it.second;
        ans += a*(a-1)/2;
    }

    cout<<ans;
}