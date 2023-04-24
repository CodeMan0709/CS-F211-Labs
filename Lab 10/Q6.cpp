#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int freq[n] = {0};
    int ans = 0;

    priority_queue<int, vector<int>, greater<int>> minheap;
    int flag = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        vector<int> temp;

        while (!minheap.empty() && minheap.top() < arr[i])
        {
            temp.push_back(minheap.top());
            minheap.pop();
            ans++;
            flag = 1;
        }

        if (flag == 1)
        {
            for (auto it : temp)
            {
                cout<<temp[it]<<" ";
                minheap.push(temp[it]);
            }
            temp.clear();
            
        }

        minheap.push(arr[i]);
    }

    cout << ans;
    return 0;
}