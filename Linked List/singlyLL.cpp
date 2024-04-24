#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *insert(Node *head, int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    cout << "Inserted " << value << " at the beginning." << endl;
    return newNode;
}
Node *insertAtPosition(Node *head, int value, int position)
{
    Node *newNode = new Node;
    newNode->data = value;

    if (position == 1)
    {
        newNode->next = head;
        cout << "Inserted " << value << " at position " << position << "." << endl;
        return newNode;
    }

    Node *temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; ++i)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Position out of range." << endl;
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Inserted " << value << " at position " << position << "." << endl;
    return head;
}
Node *deleteAtPosition(Node *head, int position)
{
    if (head == nullptr)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return nullptr;
    }

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted node at position " << position << "." << endl;
        return head;
    }

    Node *temp = head;
    Node *prev = nullptr;
    for (int i = 1; i < position && temp != nullptr; ++i)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Position out of range." << endl;
        return head;
    }
    prev->next = temp->next;
    delete temp;
    cout << "Deleted node at position " << position << "." << endl;
    return head;
}
void display(Node *head)
{
    cout << "Linked List: ";
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    int choice, value, position;

    do
    {
        cout << "\nSingly Linked List Menu\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at position\n";
        cout << "3. Delete at position\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            head = insert(head, value);
            break;
        case 2:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> position;
            head = insertAtPosition(head, value, position);
            break;
        case 3:
            cout << "Enter position to delete: ";
            cin >> position;
            head = deleteAtPosition(head, position);
            break;
        case 4:
            display(head);
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
