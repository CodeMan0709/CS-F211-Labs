#include<bits/stdc++.h>
using namespace std;

class Train
{
    public:
    int start;
    int end;
};

bool comparator(Train a,Train b)
{
    if(a.start<b.start)
    return true;
    else
    return false;
}

int main()
{
    int n;
    cin>>n;

    Train arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i].start;
        cin>>arr[i].end;
    }

    sort(arr,arr+n,comparator);

    Train ans[n];
    ans[0]=arr[0];

    int cnt=0;
    int leave=ans[0].end;

    for(int i=0;i<n;i++)
    {
        if(arr[i].start <= leave)
        {
            leave = max(leave,arr[i].end);
            ans[i-1].end = leave;
        }
        else
        {
            cnt++;
            arr[cnt]=arr[i];
            leave= max(leave,arr[i].end);
        }
    }

    cout<<n-cnt;
}