#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string sort(string &s)
{
    int arr[26]={0};

    for(int i=0;i<s.length();i++)
    {
        arr[s[i]-'a']++;
    }

    string sorted ="";

    for(int i=0;i<26;i++)
    {
        if(arr[i]>=1)
        {
            while(arr[i]--)
            sorted += char('a'+i);
        }
    }
    // cout<<sorted<<" ";
    return sorted;
}

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
        temp=sort(temp);
        mp[temp]++;
    }

    int ans = 0;

    for(auto it:mp)
    {
        int a = it.second;
        ans += (a*(a-1))/2;
    }

    cout<<ans;
}