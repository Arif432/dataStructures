#include <iostream>
#include <cmath>
using namespace std;

#define n 100

struct stacks
{
    int top;
    int arr[n];
};

stacks s2;
void push(int x)
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

bool empty()
{
    if (s2.top == -1)
        return true;

    return false;
}

bool charIsOperand(char op)
{
    if (op >= 'a' && op <= 'z')
        return true;

    return false;
}

bool weight(char operat)
{
    int priority = 0;
    if (operat == '-' || operat == '+')
        priority = 1;
    else if (operat == '*' || operat == '/')
        priority = 2;
    else if (operat == '^')
        priority = 3;
    else
        priority = 0;

    return priority;
}

string infToPost(string inp)
{
    s2.top = -1;
    string postFixExp = "";

    for (int i = 0; i < inp.size(); i++)
    {
        if (charIsOperand(inp[i]))
            postFixExp += inp[i];

        else if (inp[i] == '(')
            push(inp[i]);

        else if (inp[i] == ')')
        {
            while (!(empty()) && s2.arr[s2.top] != '(')
            {
                postFixExp += s2.arr[s2.top];
                pop();
            }
            pop();
        }

        else if (inp[i] == '-' || inp[i] == '+' || inp[i] == '*' || inp[i] == '/' || inp[i] == '^')
        {
            while (!(empty()) && s2.arr[s2.top] != '(' && weight(inp[i]))
            {
                postFixExp += s2.arr[s2.top];
                pop();
            }
            push(inp[i]);
        }
    }

    while (!(empty()))
    {
        postFixExp += s2.arr[s2.top];
        pop();
    }

    return postFixExp;
}

int main()
{
    s2.top = -1;
    cout << "enter postFix expression : ";
    string equation;
    cin >> equation;

    cout << infToPost(equation);
}