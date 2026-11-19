#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *insertBeginning(Node *head, int value)
{
    Node *newNode = new Node{value, head};
    return newNode;
}

Node *insertEnd(Node *head, int value)
{
    Node *newNode = new Node{value, NULL};
    if (!head)
        return newNode;
    Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

Node *insertPosition(Node *head, int value, int position)
{
    if (position == 1)
        return insertBeginning(head, value);
    Node *temp = head;
    for (int i = 1; temp && i < position - 1; i++)
        temp = temp->next;
    if (!temp)
        return head;
    Node *newNode = new Node{value, temp->next};
    temp->next = newNode;
    return head;
}

Node *deleteBeginning(Node *head)
{
    if (!head)
        return NULL;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *deleteEnd(Node *head)
{
    if (!head)
        return NULL;
    if (!head->next)
    {
        delete head;
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
    return head;
}

Node *deletePosition(Node *head, int position)
{
    if (!head)
        return NULL;
    if (position == 1)
        return deleteBeginning(head);
    Node *temp = head;
    for (int i = 1; temp && i < position - 1; i++)
        temp = temp->next;
    if (!temp || !temp->next)
        return head;
    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    return head;
}

void display(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;
    int choice, value, position;
    while (cin >> choice && choice != 0)
    {
        switch (choice)
        {
        case 1:
            cin >> value;
            head = insertBeginning(head, value);
            break;
        case 2:
            cin >> value;
            head = insertEnd(head, value);
            break;
        case 3:
            cin >> value >> position;
            head = insertPosition(head, value, position);
            break;
        case 4:
            head = deleteBeginning(head);
            break;
        case 5:
            head = deleteEnd(head);
            break;
        case 6:
            cin >> position;
            head = deletePosition(head, position);
            break;
        case 7:
            display(head);
            cout << endl;
            break;
        }
    }
    while (head)
        head = deleteBeginning(head);
    return 0;
}
