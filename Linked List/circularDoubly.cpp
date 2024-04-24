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

    if (head == nullptr)
    {
        newNode->prev = newNode;
        newNode->next = newNode;
        return newNode;
    }

    newNode->prev = head->prev;
    newNode->next = head;
    head->prev->next = newNode;
    head->prev = newNode;
    return newNode;
}

Node *insertEnd(Node *head, int data)
{
    Node *newNode = new Node;
    newNode->data = data;

    if (head == nullptr)
    {
        newNode->prev = newNode;
        newNode->next = newNode;
        return newNode;
    }

    newNode->prev = head->prev;
    newNode->next = head;
    head->prev->next = newNode;
    head->prev = newNode;
    return head;
}

Node *insertSpecific(Node *head, int data, int position)
{
    if (position <= 0)
    {
        cout << "Invalid position. Position should be positive." << endl;
        return head;
    }

    if (position == 1)
    {
        return insertBeginning(head, data);
    }

    Node *newNode = new Node;
    newNode->data = data;

    Node *temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Position out of range." << endl;
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return head;
}

int deleteBeginning(Node *&head)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return -1;
    }

    int data = head->data;

    if (head->next == head)
    {
        delete head;
        head = nullptr;
        return data;
    }

    Node *temp = head->next;
    temp->prev = head->prev;
    head->prev->next = temp;
    delete head;
    head = temp;
    return data;
}

int deleteEnd(Node *&head)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return -1;
    }

    int data = head->prev->data;

    if (head->next == head)
    {
        delete head;
        head = nullptr;
        return data;
    }

    Node *temp = head->prev->prev;
    temp->next = head;
    delete head->prev;
    head->prev = temp;
    return data;
}

int deleteSpecific(Node *&head, int position)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return -1;
    }

    if (position <= 0)
    {
        cout << "Invalid position. Position should be positive." << endl;
        return -1;
    }

    if (position == 1)
    {
        return deleteBeginning(head);
    }

    Node *temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == head)
    {
        cout << "Position out of range." << endl;
        return -1;
    }

    Node *delNode = temp->next;
    int data = delNode->data;
    temp->next = delNode->next;
    if (delNode->next != nullptr)
    {
        delNode->next->prev = temp;
    }
    delete delNode;
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
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void deleteList(Node *&head)
{
    if (head == nullptr)
    {
        cout << "List is already empty" << endl;
        return;
    }

    Node *temp = head;
    Node *nextNode;
    do
    {
        nextNode = temp->next;
        delete temp;
        temp = nextNode;
    } while (temp != head);

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
            el = deleteBeginning(head);
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
