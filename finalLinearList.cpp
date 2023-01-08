#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;

    node(int val)
    {
        next = NULL;
        data = val;
    }
};

void insertTop(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void insertNode(node *&head, int val)
{
    if (head == NULL)
    {
        insertTop(head, val);
        return;
    }

    node *n = new node(val);
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
}

void insertAnyPoint(node *&head, int val, int key)
{
    node *temp = head;

    while (temp != NULL)
    {
        if (key == head->data)
        {
            insertTop(head, val);
            return;
        }

        else if (temp->next->data == key)
        {
            node *n = new node(val);
            node *move = temp->next;
            temp->next = n;
            n->next = move;
            return;
        }
        temp = temp->next;
    }
}

void display(node *head)
{
    node *temp = head;

    while (temp->next != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

void deleteHead(node *&head)
{
    node *todel = head;
    head = head->next;
    delete todel;
}

void delAnyPoint(node *&head, int val)
{
    node *temp = head;
    while (head != NULL)
    {
        if (head->data == val)
        {
            deleteHead(head);
            return;
        }

        else if (temp->next->data == val)
        {
            node *todel = temp->next;
            temp->next = temp->next->next;
            delete todel;
            return;
        }

        temp = temp->next;
    }
}

int main()
{
    node *head = NULL;

    insertTop(head, 2);
    insertTop(head, 3);
    insertAnyPoint(head, 5, 2);
    insertNode(head, 4);
    insertAnyPoint(head, 9, 3);
    display(head);

    delAnyPoint(head, 5);
    display(head);
}