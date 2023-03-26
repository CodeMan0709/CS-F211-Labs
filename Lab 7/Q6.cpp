#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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

    priority_queue<int,vector<int>,greater<int> > minheap;
    
}