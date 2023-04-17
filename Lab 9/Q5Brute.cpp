#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,k,n;
    cin>>m>>k>>n;

    int arr[m][k];
    int brr[k][n];
    int ans[m][n];

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<k;j++)
        {
            arr[i][j]=0;
        }
    }

    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
        {
            brr[i][j]=0;
        }
    }

    int a;
    cin>>a;

    for(int i=0;i<a;i++)
    {
        int x,y,val;
        cin>>x>>y>>val;
        arr[x-1][y-1]=val;
    }

    int b;
    cin>>b;

    for(int i=0;i<b;i++)
    {
        int x,y,val;
        cin>>x>>y>>val;
        brr[x-1][y-1]=val;
    }


    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans[i][j]=0;

            for(int z=0;z<k;z++)
            {
                ans[i][j]+=arr[i][z]*brr[z][j];
            }
        }
    }

    int cnt=0;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(ans[i][j] != 0)
            {
                cnt++;
            }
        }
    }

    cout<<endl;
    cout<<cnt<<endl;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(ans[i][j] != 0)
            {
                cout<<i+1<<" "<<j+1<<" "<<ans[i][j]<<endl;
            }
        }
    }
    return 0;
}