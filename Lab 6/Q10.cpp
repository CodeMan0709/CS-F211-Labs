// Kumar's Code
#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
    string s;
    cin>>s;
    stack<char>stk;

    int len = s.length();
    int a=0;
    int b=0;

    for(int i=0;i<len;i++)
    {
        if(s[i]=='(')
        {
            stk.push('(');
            a++;
        }
        else if(a==0 && s[i]==')')
        {
            b++;
        }
        else if(s[i]==')')
        {
            stk.push(')');
            a--;
        }
    }

    cout<<a+b;
}
