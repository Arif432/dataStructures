#include <iostream>
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
        cout << " stack over flow";
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

int decimalToBin(int numb)
{
    while (numb > 0)
    {
        push(numb % 2);
        numb = numb / 2;
    }
}

int main()
{
    s2.top = -1;
    int numb;
    cout << "enter number : ";
    cin >> numb;

    decimalToBin(numb);

    disp();

    return 0;
}