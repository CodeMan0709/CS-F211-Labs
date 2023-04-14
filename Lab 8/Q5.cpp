// Gaurav pro such chad solution
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    map<int, bool, greater<int>> mp[m];
    unordered_map<int, int> freq;

    for (int i = 0; i < m; i++)
    {
        int cur = arr[i];

        if (freq.find(cur) == freq.end())
        {
            freq[cur] = 1;
            mp[0][cur] = 1;
        }
        else
        {
            int currfreq = freq[cur];
            mp[currfreq - 1].erase(cur);
            freq[cur]++;
            mp[currfreq][cur] = 1;
        }
    }

    if (mp[k - 1].empty())
        cout << -1 << endl;
    else
        cout << mp[k - 1].begin()->first << endl;

    for (int i = m; i < n; i++)
    {
        int rem = arr[i - m];
        int currfreq = freq[rem];
        mp[currfreq - 1].erase(rem);
        freq[rem]--;

        if (freq[rem] == 0)
            freq.erase(rem);
        else
            mp[freq[rem] - 1][rem] = 1;

        int curr = arr[i];
        if (freq.find(curr) == freq.end())
        {
            freq[curr] = 1;
            mp[0][curr] = 1;
        }
        else
        {
            int currfreq = freq[curr];
            mp[currfreq - 1].erase(curr);
            freq[curr]++;
            mp[currfreq][curr] = 1;
        }

        if (mp[k - 1].empty())
            cout << -1 << endl;
        else
            cout << mp[k - 1].begin()->first << endl;
    }
}