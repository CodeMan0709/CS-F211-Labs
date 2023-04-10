//GFG
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int pre = 0;
    map<int,int>xorr;
    int ans=0;

    for(int i=0;i<n;i++)
    {
        pre = pre^arr[i];

        if(pre==0)
        ans++;

        int temp = pre;

        if(xorr.find(temp) != xorr.end())
        {
            ans += xorr[temp];
        }

        xorr[pre]++;
    }

    cout<<ans<<endl;
}    