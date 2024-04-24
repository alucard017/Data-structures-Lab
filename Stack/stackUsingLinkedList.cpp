#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *top = nullptr;
void push(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    if (top == nullptr)
    {
        top = newNode;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}
int pop()
{
    if (top == nullptr)
    {
        return -1;
    }
    int data = top->data;
    Node *temp = top;
    top = top->next;
    delete temp;
    return data;
}
void display()
{
    Node *temp = top;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display();
    cout << pop() << endl;
}