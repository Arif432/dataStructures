#include <iostream>
using namespace std;

struct node
{
public:
    int info;
    node *next;

    node(int x)
    {
        info = x;
        next = NULL;
    }
};

void insertTop(node *&head, int val)
{
    node *n = new node(val);

    if (head == nullptr)
    {
        n->next = n;
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val)
{
    if (head == nullptr)
    {
        insertTop(head, val);
        return;
    }

    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    node *n = new node(val);
    temp->next = n;
    n->next = head;
}

void insertAnyPoint(node *&head, int val, int key)
{
    node *temp = head;

    while (temp != NULL)
    {
        if (key == head->info)
        {
            insertTop(head, val);
            return;
        }

        else if (temp->next->info == key)
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

void delHead(node *&head)
{
    node *del = head;

    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = head->next;
    head = head->next;
    delete del;
}

void delAnyPoint(node *&head, int val)
{
    node *temp = head;
    while (temp->next != head)
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
    do
    {
        cout << temp->info << " ";
        temp = temp->next;
    } while (temp != head);
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 2);
    insertAtTail(head, 4);
    insertTop(head, 3);
    insertTop(head, 5);
    insertAnyPoint(head, 3, 5);
    delAnyPoint(head, 4);
    display(head);
}

// void sortList(node *&head)
// {
//     // Current will point to head
//     struct node *current = head, *index = NULL;
//     int temp;
//     if (head == NULL)
//     {
//         printf("List is empty");
//     }
//     else
//     {
//         do
//         {
//             // Index will point to node next to current
//             index = current->next;
//             while (index != head)
//             {
//                 // If current node is greater than index data, swaps the data
//                 if (current->info > index->info)
//                 {
//                     temp = current->info;
//                     current->info = index->info;
//                     index->info = temp;
//                 }
//                 index = index->next;
//             }
//             current = current->next;
//         } while (current->next != head);
//     }
// }
