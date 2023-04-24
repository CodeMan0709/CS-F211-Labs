#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    int sum_a = 0, sum_b = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum_a += a[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        sum_b += b[i];
    }

    if (sum_a == sum_b)
    {
        cout << "Yes" << endl;
        return 0;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        int diff = sum_a - a[i] + b[j] - (sum_b - b[j] + a[i]);
        if (diff == 0)
        {
            cout << "Yes" << endl;
            return 0;
        }
        else if (diff < 0)
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    if (i < n && j < m)
    {
        int diff = sum_a - a[i] + b[j] - (sum_b - b[j] + a[i]);
        if (diff == 0)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
