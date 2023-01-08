#include <iostream>
using namespace std;

struct node
{
public:
    int info;
    node *prev;
    node *next;

    node(int val)
    {
        info = val;
        prev = NULL;
        next = NULL;
    }
};

void insertTop(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    n->prev = nullptr;

    if (head != NULL)
        head->prev = n;

    head = n;
}

void insertNode(node *&head, int val)
{
    if (head == NULL)
    {
        insertTop(head, val);
        return;
    }

    node *temp = head;
    node *n = new node(val);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->prev = temp;
}

void delHead(node *&head)
{
    node *todel = head;
    head = head->next;
    head->prev = nullptr;
    delete todel;
}

void delAnypoint(node *&head, int val)
{
    node *temp = head;
    while (temp != nullptr)
    {
        if (head->info == val)
        {
            delHead(head);
            return;
        }

        else if (temp->next->info == val)
        {
            node *todel = temp->next;
            temp->next = temp->next->next;
            delete todel;
            return;
        }

        temp = temp->next;
    }
}

void display(node *head)
{
    node *temp = head;
    while (temp->next != nullptr)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << temp->info << " ";
    cout << endl;
}

int main()
{
    node *head = NULL;

    insertTop(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    delAnypoint(head, 4);
    display(head);
}