#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;

    int arr[m][n];

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    int k;
    cin>>k;

    int r=0;
    int c=n-1;

    bool flag=false;

    while(r<m && c>=0)
    {
        if(arr[r][c] ==k)
        {
            cout<<"YES"<<endl;
            flag=true;
            break;
        }

        if(arr[r][c]<k)
        {
            r++;
        }
        else
        {
            c--;
        }
    }

    if(!flag)
    cout<<"NO";

    return 0;
}