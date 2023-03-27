#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    priority_queue<int>heap;

    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        heap.push(temp);
    }

    while(m>0)
    {
        int x = heap.top();
        heap.pop();
        x = x/2;
        heap.push(x);
        m--;
    }

    int ans=0;

    for(int i=0;i<n;i++)
    {
        int temp = heap.top();
        ans = ans + temp;
        heap.pop();
    }

    cout<<ans<<endl;

    return 0;
}