#include <iostream>
using namespace std;

class Stack
{
private:
    int size;
    int *arr;
    int top;

public:
    Stack(int sz)
    {
        size = sz;
        arr = new int[size];
        top = -1;
    }

    void push(int val)
    {
        if (top == size - 1)
        {
            throw "Stack overflow";
        }
        top++;
        arr[top] = val;
    }

    void pop()
    {
        if (top == -1)
        {
            throw "Stack underflow";
        }
        top--;
    }

    int peek()
    {
        if (top == -1)
        {
            throw "Stack empty";
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    int getSize()
    {
        return top + 1;
    }
};

class MinStack
{

private:
    Stack elements;
    Stack minimums;

public:
    MinStack(int sz) : elements(sz), minimums(sz)
    {
    }

    void push(int val)
    {
        elements.push(val);
        if (minimums.isEmpty() || val <= minimums.peek())
        {
            minimums.push(val);
        }
    }

    void pop()
    {
        if (elements.peek() == minimums.peek())
        {
            minimums.pop();
        }
        elements.pop();
    }

    int top()
    {
        return elements.peek();
    }

    int getMin()
    {
        return minimums.peek();
    }
};

int main()
{
    int n, m;
    cin >> n;

    MinStack st(n);
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        st.push(val);
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int val;
            cin >> val;
            st.push(val);
        }
        else if (op == 2)
        {
            st.pop();
        }
        else if (op == 3)
        {
            cout << st.top() << endl;
        }
        else if (op == 4)
        {
            cout << st.getMin() << endl;
        }
    }

    return 0;
}
