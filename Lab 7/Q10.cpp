#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    priority_queue<int> a;
    priority_queue<int> b;

    int arr[n];
    int brr[n];

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push(x);
    }

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        b.push(x);
    }

    for(int i=0;i<n;i++)
    {
        arr[i] = a.top();
        a.pop();
        brr[i] = b.top();
        b.pop();
    }

    priority_queue<pair<int,pair<int,int>>> c;

    c.push(make_pair(arr[0]+brr[0],make_pair(0,0)));

    for(int i=0;i<k;i++)
    {
        pair<int,pair<int,int>> temp = c.top();
        cout<<temp.first<<" ";
        c.pop();       
        c.push(make_pair(arr[temp.second.first]+brr[temp.second.second + 1],make_pair(temp.second.first,temp.second.second +1)));
        c.push(make_pair(arr[temp.second.first+1]+brr[temp.second.second],make_pair(temp.second.first+1,temp.second.second)));
    }
}