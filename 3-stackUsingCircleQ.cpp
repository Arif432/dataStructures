#include <iostream>
using namespace std;

#define n 3

int rear = -1;
int front = -1;
int arrayQ[n];

void enqueuePUSH(int inp)
{
    if (front == 0 && rear == n - 1 || front != 0 && rear == n - 1)
        cout << "queue overflow";

    else if (rear == -1 && front == -1)
    {
        front++;
        rear++;
        arrayQ[rear] = inp;
    }

    else
    {
        rear++;
        front++;
        arrayQ[rear] = inp;
    }
}

void dequeuePOP()
{
    if (front == -1 || rear == -1)
        cout << "queue under flow";

    else if (front == rear)
        front--;
    else if (front == n - 1)
        front--;
    else
        front--;
}

void display()
{
    for (int i = front; i >= 0; i--)
        cout << arrayQ[i];
}

int main()
{
    enqueuePUSH(2);
    enqueuePUSH(4);
    enqueuePUSH(3);

    dequeuePOP();

    display();
}