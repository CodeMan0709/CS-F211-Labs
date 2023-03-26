#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ppi pair<int,pair<int,int>>

int main()
{
    int k;
    cin>>k;

    vector<vector<int>> v;

    for(int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        vector<int> t;
        for(int j=0;j<x;j++)
        {
            int temp;
            cin>>temp;
            t.push_back(temp);
        }
        v.push_back(t);
    }

    priority_queue<ppi,vector<ppi>,greater<ppi>> minheap;

    for(int i=0;i<k;i++)
    {
        minheap.push(make_pair(v[i][0],make_pair(i,0)));
    }

    vector<int>ans;

    while(minheap.empty()!=1)
    {
        int val = minheap.top().first;
        int row = minheap.top().second.first;
        int index = minheap.top().second.second;
        minheap.pop();

        ans.push_back(val);

        if(index<v[row].size()-1)
        minheap.push(make_pair(v[row][index+1],make_pair(row,index+1)));
    }
    
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}