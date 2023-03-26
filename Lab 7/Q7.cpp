#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    priority_queue<int> heap ;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        heap.push(x);
    }

    int ans = 0;

    while(k>0)
    {
        int temp =0;

        if(heap.top()%2)
        temp = heap.top()/2 + 1;
        else
        temp = heap.top()/2;

        ans = ans + temp;

        int x = heap.top() - temp;
        heap.pop();
        heap.push(x);

        k--;
    }

    cout<<ans<<endl;
}