#include <iostream>
#include <map>
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

    int lit=0;
    int nolit=0;
    int l=0;
    int r=0;
    int ans=0;

    if(arr[0]==0)
    nolit++;
    else
    lit++;

    while(r<n && l<=r)
    {
        if(lit>k)
        {
            if(arr[l]==1)
            lit--;
            else
            nolit--;

            l++;
        }

        if(lit<=k)
        {
            ans = ans + r - l + 1;
            r++;

            if(arr[r]==1)
            lit++;
            else
            nolit++;
        }
    }

    cout<<ans<<endl;
    
}