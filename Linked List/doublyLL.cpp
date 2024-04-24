#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

char ch;
int data, position, el;

Node *insertBeginning(Node *head, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = head;
    if (head != nullptr)
        head->prev = newNode;
    return newNode;
}

Node *insertEnd(Node *head, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    if (head == nullptr)
    {
        newNode->prev = nullptr;
        return newNode;
    }

    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

Node *insertSpecific(Node *head, int data, int position)
{
    if (position == 1)
    {
        return insertBeginning(head, data);
    }
    else if (position > 1)
    {
        Node *newNode = new Node;
        newNode->data = data;

        Node *current = head;
        for (int i = 1; i < position - 1 && current != nullptr; i++)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Not Possible to add as required position doesn't exist\n";
            return head;
        }

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr)
            current->next->prev = newNode;
        current->next = newNode;
        return head;
    }
    else
    {
        cout << "Invalid position\n";
        return head;
    }
}

int deleteBegin(Node *&head)
{
    if (head == nullptr)
    {
        cout << "List is empty\n";
        return -1;
    }

    int data = head->data;
    Node *temp = head;
    head = head->next;
    if (head != nullptr)
        head->prev = nullptr;
    delete temp;
    return data;
}

int deleteEnd(Node *&head)
{
    if (head == nullptr)
    {
        cout << "List is empty\n";
        return -1;
    }

    int data;
    if (head->next == nullptr)
    {
        data = head->data;
        delete head;
        head = nullptr;
        return data;
    }

    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    data = current->data;
    if (current->prev != nullptr)
        current->prev->next = nullptr;
    delete current;
    return data;
}

int deleteSpecific(Node *&head, int position)
{
    if (head == nullptr)
    {
        cout << "List is empty\n";
        return -1;
    }

    if (position <= 1)
    {
        return deleteBegin(head);
    }

    Node *current = head;
    for (int i = 1; i < position - 1 && current != nullptr; i++)
    {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr)
    {
        cout << "Element at position doesn't exist" << endl;
        return -1;
    }

    Node *temp = current->next;
    int data = temp->data;
    current->next = temp->next;
    if (temp->next != nullptr)
        temp->next->prev = current;
    delete temp;
    return data;
}

void traverseList(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }

    cout << "List is:" << endl;
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void deleteList(Node *&head)
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    cout << "List is Deleted" << endl;
}

int main()
{
    Node *head = nullptr;

    do
    {
        cout << "1. Insertion at Beginning\n2. Insertion at End\n3. Insertion at specific position\n"
             << "4. Deletion from beginning\n5. Deletion from end\n6. Deletion from specific position\n"
             << "7. Traverse List\n8. Delete the List\n";
        int choice;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element to insert: ";
            cin >> data;
            head = insertBeginning(head, data);
            cout << "Element inserted at Beginning\n";
            break;
        case 2:
            cout << "Enter element to insert: ";
            cin >> data;
            head = insertEnd(head, data);
            cout << "Element inserted at End\n";
            break;
        case 3:
            cout << "Enter element to insert: ";
            cin >> data;
            cout << "Enter Position: ";
            cin >> position;
            head = insertSpecific(head, data, position);
            break;
        case 4:
            el = deleteBegin(head);
            if (el != -1)
            {
                cout << "Deleted Element from Beginning is: " << el << endl;
            }
            break;
        case 5:
            el = deleteEnd(head);
            if (el != -1)
            {
                cout << "Deleted Element from End is: " << el << endl;
            }
            break;
        case 6:
            cout << "Enter the position to delete from: ";
            cin >> position;
            el = deleteSpecific(head, position);
            if (el != -1)
            {
                cout << "Deleted Element from Given Position is: " << el << endl;
            }
            break;
        case 7:
            traverseList(head);
            break;
        case 8:
            deleteList(head);
            break;
        default:
            cout << "Invalid choice\n";
        }

        cout << "Do You Want to continue(Y/N): ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}
