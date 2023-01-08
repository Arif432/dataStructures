#include <iostream>
using namespace std;

#define n 3

int rear = -1;
int front = -1;
int arrayQ[n];

void enqueue(int inp)
{
    if (rear == n - 1)
        cout << "queue over flow";

    else if (front == -1)
    {
        front++;
        rear++;
        arrayQ[rear] = inp;
    }

    else
    {
        rear++;
        arrayQ[rear] = inp;
    }
}

void deQueue()
{
    if (front > rear || front == -1 || rear == -1)
        cout << "queue under flow";

    else
        front++;
}

void display()
{
    for (int i = front; i <= rear; i++)
        cout << arrayQ[i];
}

int main()
{

    enqueue(2);
    enqueue(2);

    display();
}