#include <iostream>
#include <map>
using namespace std;

int main()
{
    int lim;
    cin>>lim;
    int n;
    cin>>n;

    map<int,int>m;

    for(int i=0;i<n;i++)
    {
        int a,x;
        cin>>a>>x;

        if(a==1)
        {
            if(m.find(x)==m.end())
            {
                m[x]=1;
            }
            else if(m[x]==1)
            {
                m.erase(x);
            }
        }
        else if(a==2)
        {
            if(m.upper_bound(x)==m.end())
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<m.upper_bound(x)->first<<endl;
            }
        }
        else if(a==3)
        {
            auto t = m.lower_bound(x);
            t--;

            if(t==m.end())
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<(t)->first<<endl;
            }
        }
    }
}