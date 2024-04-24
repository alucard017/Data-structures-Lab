#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *front = nullptr;
Node *rear = nullptr;

void enqueue(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if (front == nullptr)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    if (front == nullptr)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    Node *temp = front;
    front = front->next;
    delete temp;
    if (front == nullptr)
    {
        rear = nullptr;
    }
}

int peek()
{
    if (front == nullptr)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return front->data;
}

bool isEmpty()
{
    return front == nullptr;
}

void display()
{
    if (front == nullptr)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    Node *temp = front;
    cout << "Queue: ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    cout << "Front element: " << peek() << endl;

    dequeue();
    dequeue();

    display();

    return 0;
}
