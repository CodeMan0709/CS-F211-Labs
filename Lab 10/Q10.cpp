#include<bits/stdc++.h>
using namespace std;
#define ppi pair<int,pair<int,int>>

int main()
{
    int n,k;
    cin>>n>>k;

    int arr[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    priority_queue<ppi,vector<ppi>,greater<ppi>> minheap;

    for(int i=0;i<n;i++)
    {
        minheap.push({arr[0][i],{0,i}});
    }

    for(int i=0;i<k-1;i++)
    {
        ppi temp = minheap.top();
        minheap.pop();

        minheap.push({arr[temp.second.first + 1][temp.second.second],{temp.second.first+1,temp.second.second}});
    }

    cout<<minheap.top().first;
    return 0;
}