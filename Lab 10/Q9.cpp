#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int arr[n];
    int brr[m];

    map<int,int> mp;
    int sumA=0,sumB=0;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sumA+=arr[i];
    }

    for(int i=0;i<m;i++)
    {
        cin>>brr[i];
        sumB+=brr[i];
        mp[brr[i]]=1;
    }

    for(int i=0;i<n;i++)
    {
        int bi = (sumB-sumA)/2 + arr[i];

        if(mp.find(bi)!=mp.end() && ((sumB-sumA+2*arr[i])%2==0))
        {
            cout<<"Yes";
            return 0;
        }
    }

    cout<<"No";


    return 0;
}
