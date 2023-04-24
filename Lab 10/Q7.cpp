#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    deque<int> temp;

    for(int i=0;i<n;i++)
    {
        while(!temp.empty() && arr[temp.back()]<arr[i])
        temp.pop_back();

        temp.push_back(i);

        if(i+1 >= k)
        {
            if(temp.front() == i-k)
            temp.pop_front();

            cout<<arr[temp.front()]<<" ";
        }
    }
    return 0;
}