#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    map<int,int> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }

    int ans=0;

    for(auto x:mp)
    {
        auto it = mp.upper_bound(x.first+k-1);

        if(it!=mp.end())
        {
            if(x.second>1)
            {
                (x.second)--;
                ans++;
            }
            else
            {
                mp.erase(it);
                ans++;
            }

        }
    }

    cout<<ans;

    // sort(arr, arr + n);

    // int start = 0;
    // int end = 1;
    // int answer = 0;

    // while (start <= end && end < n)
    // {
    //     if (arr[end] - arr[start] < k)
    //     {
    //         end++;
    //     }
    //     else
    //     {
    //         answer++;
    //         start++;
    //         end++;
    //     }
    // }
    // cout << answer;
}