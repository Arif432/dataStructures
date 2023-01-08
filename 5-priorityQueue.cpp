#include <iostream>
using namespace std;

#define n 3

struct priorityQ
{
    int priority = -1;
    int value = -1;
    int size = -1;
};

int arrayQ[n];

priorityQ q[n];

void enque(int val, int priority)
{
    q->size++;
    q[q->size].value = val;
    q[q->size].priority = priority;
}

int peek()
{
    int highestPriority = -1000;

    int indexOfHighPriority = -1;

    for (int i = 0; i <= q->size; i++)
    {
        if (highestPriority == q[i].priority && indexOfHighPriority > -1 &&
            q[i].value > q[indexOfHighPriority].value)
        {
            indexOfHighPriority = i;
            highestPriority = q[i].priority;
        }

        else if (highestPriority < q[i].priority)
        {
            indexOfHighPriority = i;
            highestPriority = q[i].priority;
        }
    }

    return indexOfHighPriority;
}

void deQueue()
{
    int index = peek();

    for (int i = index; i <= q->size; i++)
        q[i] = q[i + 1];

    q->size--;
}

void display()
{
    for (int i = 0; i <= q->size; i++)
        cout << q[i].value << " " << q[i].priority << endl;
}

int main()
{
    enque(1, 2);
    enque(3, 4);
    enque(5, 6);
    enque(4, 6);

    deQueue();

    display();
}