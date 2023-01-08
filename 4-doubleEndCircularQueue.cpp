#include <iostream>
using namespace std;

#define n 3

int rear = -1;
int front = -1;
int arrayQ[n];

void enqueueRear(int val)
{
    if (front == 0 && rear == n - 1 || front > rear)
        cout << "queue over flow";
    else if (rear == -1 && front == -1)
    {
        rear++;
        front++;
        arrayQ[rear] = val;
    }
    else if (rear == n - 1 && front != 0)
    {
        rear = 0;
        arrayQ[rear] = val;
    }
    else
        arrayQ[++rear] = val;
}

void enqueueFront(int val)
{
    if (front == 0 && rear == n - 1)
        cout << "over flow";
    else if (front == -1 && rear == -1)
    {
        rear++;
        front++;
        arrayQ[rear] = val;
    }
    else if (rear != n - 1 && front == 0)
    {
        front = n - 1;
        arrayQ[front] = val;
    }
    else
        arrayQ[--front] = val;
}

void dequeueRear()
{
    if (front == -1 && rear == -1)
        cout << "under flow dequeue";
    else if (rear == front)
    {
        cout << "empty queue";
        rear = -1;
        front = -1;
    }
    else if (rear == 0)
        rear = n - 1;
    else
        rear--;
}

void dequeueFront()
{
    if (front == -1 && rear == -1)
    {
        cout << "under flow";
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
        cout << "empty queueu";
    }
    else if (front == n - 1)
    {
        front = 0;
    }
    else
        front++;
}

// void enqueueRear(int val)
// {
//     if (front == 0 && rear == n - 1 || front > rear)
//         cout << "queue over flow";

//     else if (front == -1 && rear == -1)
//     {
//         front++;
//         arrayQ[++rear] = val;
//     }
//     else if (front != 0 && rear == n - 1)
//     {
//         rear = 0;
//         arrayQ[rear] = val;
//     }

//     else
//     {
//         arrayQ[++rear] = val;
//     }
// }

// void dequeueFront()
// {
//     if (front == -1 && rear == -1)
//         cout << "queue under flow";

//     else if (front == rear)
//     {
//         cout << "queue empyt";
//         front = -1;
//         rear = -1;
//     }
//     else if (front == n - 1)
//         front = 0;

//     else
//         front++;
// }

// void dequeueRear()
// {
//     if (rear == -1 && front == -1)
//         cout << "under flow";

//     else if (rear == front)
//     {
//         cout << "empty";
//         front = -1;
//         rear = -1;
//     }
//     else if (rear == 0)
//         rear = n - 1;
//     else
//         rear--;
// }

// void enqueueFront(int val)
// {
//     if (front == 0 && rear == n - 1 || front > rear)
//     {
//         cout << "over flow";
//     }
//     else if (front == -1 && rear == -1)
//     {
//         front++;
//         rear++;
//         arrayQ[rear] = val;
//     }
//     else if (front == 0 && rear != n - 1)
//     {
//         front = n - 1;
//         arrayQ[front] = val;
//     }

//     else
//     {
//         front--;
//         arrayQ[front] = val;
//     }
// }

void display()
{
    int i = 0;
    for (i = front; i != rear; i = (i + 1) % n)
        cout << arrayQ[i];

    cout << arrayQ[i];
}

int main()
{
    enqueueRear(2);
    enqueueRear(3);
    enqueueRear(4);

    dequeueRear();

    enqueueFront(8);

    display();
}