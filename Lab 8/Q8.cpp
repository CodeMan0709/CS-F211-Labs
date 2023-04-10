#include <iostream>
#include <map>
using namespace std;

int main()
{
    string in;
    cin >> in;

    map<string, int> m;

    for (int i = 0; i < in.size() - 10; i++)
    {
        string temp = "";

        for (int j = i; j < i + 10; j++)
        {
            temp += in[j];
        }

        if (m.find(temp) == m.end())
        {
            m[temp] = 1;
        }
        else
        {
            m[temp]++;
        }
    }

    int ans=0;

    for(auto x:m)
    {
        if(x.second>1)
        {
            ans++;
        }
    }

    cout<<ans<<endl;

    for(auto x:m)
    {
        if(x.second>1)
        {
            cout<<x.first<<endl;
        }
    }
}