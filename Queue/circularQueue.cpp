#include <iostream>
using namespace std;
int queue[5];
int front = -1, rear = -1, size = 5;
void insert(int value);
void deleteQueue();
void display();

int main()
{
    int choice, value;
    cout << "1.Insert\n";
    cout << "2.Delete\n";
    cout << "3.Display\n";

    do
    {
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> value;
            insert(value);
            break;
        case 2:
            deleteQueue();
            break;
        case 3:
            display();
            break;
        }
    } while (choice != 3);

    return 0;
}
void insert(int value)
{
    if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
    {
        cout << "\nQueue is full\n";
        return;
    }
    else if (front == -1)
    {
        front = rear = 0;
        queue[rear] = value;
    }
    else
    {
        rear = (rear + 1) % size;
        queue[rear] = value;
    }
}
void deleteQueue()
{
    if (front == -1)
    {
        cout << "Queue Underflow\n";
        return;
    }

    cout << "Element deleted from queue is : " << queue[front] << "\n";

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }

    else
    {
        if (front == size - 1)
            front = 0;
        else
            front = front + 1;
    }
}

void display()
{
    if (front == -1)
    {
        cout << "\nQueue is Empty";
        return;
    }

    cout << "\nCircular Queue elements are: ";

    if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
    }
    else
    {
        for (int i = front; i < size; i++)
            cout << queue[i] << " ";

        for (int i = 0; i <= rear; i++)
            cout << queue[i] << " ";
    }
}
