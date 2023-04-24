#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;

    int arr[a];
    int brr[b];
    
    for (int i = 0; i < a; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < b; i++)
    {
        cin >> brr[i];
    }

    sort(arr, arr + a);

    map<int, int> mp;

    for (int i = 0; i < b; i++)
    {
        mp[brr[i]] = 0;
    }

    for (int i = 0; i < a; i++)
    {
        if (mp.find(arr[i]) != mp.end())
            mp[arr[i]]++;
    }

    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < mp[brr[i]]; j++)
        {
            cout << brr[i] << " ";
        }
    }

    for (int i = 0; i < a; i++)
    {
        if (mp.find(arr[i]) == mp.end())
        {
            cout << arr[i] << " ";
        }
    }

    return 0;
}    