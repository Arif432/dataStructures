using namespace std;
#include <iostream>

struct Node
{
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    inorder(head->left);
    cout << head->data << "  ";
    inorder(head->right);
}

void preOrder(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    cout << head->data;
    preOrder(head->left);
    preOrder(head->right);
}

void postOrder(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    postOrder(head->left);
    postOrder(head->right);
    cout << head->data;
}

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        // new node to right is create
        root->right = insert(root->right, val);
    }

    return root;
}

Node *search(Node *head, int find)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (head->data == find)
    {
        return head;
    }
    else if (find < head->data)
    {
        return search(head->left, find);
    }

    return search(head->right, find);
}

Node *inOrderSucc(Node *head)
{
    Node *curr = head;

    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

// last child , node with 1 child ,ndoe with 2 child
Node *deleteNode(Node *root, int val)
{
    if (val < root->data)
    {
        root->left = deleteNode(root->left, val);
    }
    if (val > root->data)
    {
        root->right = deleteNode(root->right, val);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = inOrderSucc(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, val);
    }

    return root;
}

int main()
{
    Node *head = NULL;

    head = insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);

    //    // inorder(head);
    //     cout << endl;
    //     preOrder(head);
    //     cout << endl;
    //     postOrder(head);
    //     cout << endl;

    // if (search(head, 3) != NULL)
    // {
    //     cout << "exist";
    // }

    inorder(head);
    cout << endl;
    head = deleteNode(head, 5);
    inorder(head);
    cout << endl;
}