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

void calcualtions(char op)
{
    int var1, var2;

    var2 = s2.arr[s2.top];
    pop();
    var1 = s2.arr[s2.top];
    pop();

    switch (op)
    {
    case '+':
        push(var1 + var2);
        break;
    case '-':
        push(var1 - var2);
        break;
    case '/':
        push(var1 / var2);
        break;
    case '*':
        push(var1 * var2);
        break;
    case '^':
        push(pow(var1, var2));
        break;
    default:
        cout << "unidentified operator";
        break;
    }
}

int main()
{
    s2.top = -1;
    cout << "enter postFix expression : ";
    string equation;
    cin >> equation;

    for (int i = 0; i < equation.size(); i++)
    {

        if (equation[i] >= '0' && equation[i] <= '9')
        {
            push(equation[i] - '0');
        }
        else if (equation[i] == '+')
        {
            if (s2.top > 0)
                calcualtions('+');
            else
            {
                cout << "imabalance equation can't be solved";
                break;
            }
        }

        else if (equation[i] == '-')
        {
            if (s2.top > 0)
                calcualtions('-');
            else
            {
                cout << "imabalance equation can't be solved";
                break;
            }
        }

        else if (equation[i] == '/')
        {
            if (s2.top > 0)
                calcualtions('/');
            else
            {
                cout << "imabalance equation can't be solved";
                break;
            }
        }

        else if (equation[i] == '*')
        {
            if (s2.top > 0)
                calcualtions('*');
            else
            {
                cout << "imabalance equation can't be solved";
                break;
            }
        }

        else if (equation[i] == '^')
        {
            if (s2.top > 0)
                calcualtions('^');
            else
            {
                cout << "imabalance equation can't be solved";
                break;
            }
        }
    }

    if (s2.top != 0)
        cout << "equation is'nt balanced" << endl;

    disp();
}