#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *insertBeginning(Node *head, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    if (head == nullptr)
    {
        newNode->next = newNode;
        return newNode;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return newNode;
}

Node *insertEnd(Node *head, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    if (head == nullptr)
    {
        newNode->next = newNode;
        return newNode;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

Node *deleteBeginning(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return nullptr;
    }
    if (head->next == head)
    {
        delete head;
        return nullptr;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = head->next;
    Node *temp2 = head;
    head = head->next;
    delete temp2;
    return head;
}

void displayList(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    char choice;
    int data;

    do
    {
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Delete from beginning\n";
        cout << "4. Display the list\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            cout << "Enter data to insert: ";
            cin >> data;
            head = insertBeginning(head, data);
            break;
        case '2':
            cout << "Enter data to insert: ";
            cin >> data;
            head = insertEnd(head, data);
            break;
        case '3':
            head = deleteBeginning(head);
            break;
        case '4':
            displayList(head);
            break;
        case '5':
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please enter again.\n";
        }
    } while (choice != '5');
    Node *temp = head;
    if (temp != nullptr)
    {
        Node *prev = nullptr;
        do
        {
            prev = temp;
            temp = temp->next;
            delete prev;
        } while (temp != head);
    }

    return 0;
}
