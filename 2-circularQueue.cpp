#include <iostream>
using namespace std;

#define n 3

int rear = -1;
int front = -1;
int arrayQ[n];

void enqueue(int input)
{
    if (front == 0 && rear == n - 1)
        cout << "queue overflow";

    else if (rear == -1 && front == -1)
    {
        front++;
        rear++;
        arrayQ[rear] = input;
    }

    else if (front != 0 && rear == n - 1)
    {
        rear = 0;
        arrayQ[rear] = input;
    }
    else
    {
        rear++;
        arrayQ[rear] = input;
    }
}

void dequeue()
{
    if (rear == -1 || front == -1)
        cout << "queue under flow";

    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }

    else if (front == n - 1)
        front = 0;

    else
        front++;
}

void display()
{
    int i = 0;
    for (i = front; i != rear; i = (i + 1) % n)
    {
        cout << arrayQ[i];
    }
    cout << arrayQ[i];
}

int main()
{
    enqueue(3);
    enqueue(4);

    dequeue();
    dequeue();
    dequeue();

    display();
}