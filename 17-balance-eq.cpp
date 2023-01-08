#include <iostream>
using namespace std;

#define n 100

struct stacks
{
    int top;
    char arr[n];
};

stacks s2;
void push(char x)
{
    if (s2.top == n - 1)
        cout << "stack over flow";
    else
    {
        s2.top = s2.top + 1;
        s2.arr[s2.top] = x;
    }
}

void pop()
{
    if (s2.top == -1)
        cout << "stack under flow";
    else
        s2.top = s2.top - 1;
}

void disp()
{
    if (s2.top == -1)
        cout << "stack empty";
    else
    {
        for (int i = s2.top; i >= 0; i--)
            cout << s2.arr[i];
    }
}

int main()
{
    s2.top = -1;

    string equation;
    cout << "enter equation" << endl;
    cin >> equation;

    bool ans = true;

    for (int i = 0; i < equation.size(); i++)
    {
        if (equation[i] == '(' || equation[i] == '{' || equation[i] == '[')
            push(equation[i]);

        else if (equation[i] == ')')
        {
            if (!(s2.top == -1) && s2.arr[s2.top] == '(')
                pop();
            else
            {
                ans = false;
                break;
            }
        }
        else if (equation[i] == '}')
        {
            if (!(s2.top == -1) && s2.arr[s2.top] == '{')
                pop();
            else
            {
                ans = false;
                break;
            }
        }
        else if (equation[i] == ']')
        {
            if (!(s2.top == -1) && s2.arr[s2.top] == '[')
                pop();
            else
            {
                ans = false;
                break;
            }
        }
    }

    if (s2.top != -1)
        ans = false;

    cout << ans << endl;
    disp();
    return 0;
}