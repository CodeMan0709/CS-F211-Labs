#include <iostream>
#include <stack>
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

    stack<int> stk;
    stk.push(-1);
    int max_area = 0;

    for (int i = 0; i < n; i++)
    {
        while (stk.top() != -1 and arr[stk.top()] >= arr[i])
        {
            int current_height = arr[stk.top()];
            cout<<current_height<<" ";
            stk.pop();
            int current_width = i - stk.top() - 1;
            cout<<current_width<<" ";
            max_area = max(max_area, current_height * current_width);

        }
        stk.push(i);
    }

    while (stk.top() != -1)
    {
        int current_height = arr[stk.top()];
        stk.pop();
        int current_width = n - stk.top() - 1;
        max_area = max(max_area, current_height * current_width);
    }
    cout<<max_area;
}

//     int a[n];
//     int b[n];
//     int k=0;
//     stack<int> prev_small;
//     stack<int>next_small;

//     for (int i = 0; i < n; i++)
//     {
//         while (!prev_small.empty() && prev_small.top() >= arr[i])
//         {
//             prev_small.pop();
//         }
//         if (prev_small.empty())
//             a[k++]=-1;
//         else
//             a[k++]=prev_small.top();

//         prev_small.push(i);
//     }

//     k=n-1;

//     for(int i=n-1;i>=0;i--)
//     {
//         while(!next_small.empty() && next_small.top()>=arr[i])
//         {
//             next_small.pop();
//         }
//         if(next_small.empty())
//             b[k--]=-1;
//         else
//             b[k--]=next_small.top();
//         next_small.push(i);
//     }

//     for(int i=0;i<n;i++)
//     {
//         cout<<a[i]<<" "<<b[i]<<endl;
//     }

//     int maxans=0;
//     for(int i=0;i<n;i++)
//     {
//         int cur=(b[i]-a[i]-1)*arr[i];
//         maxans=max(cur,maxans);
//     }
//     cout<<maxans<<endl;
//     return 0;
// }