#include <iostream>
using namespace std;

int queue[5];
int front = -1, rear = -1, size = 5;

void insert(int value)
{
    if (rear == size - 1)
    {
        cout << "\nQueue is full\n";
        return;
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
    }
}

void deleteQueue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty\n";
        return;
    }
    else
    {
        cout << "Element deleted from queue is : " << queue[front] << "\n";
        front++;
    }
}

void display()
{
    if (front == -1)
    {
        cout << "\nQueue is empty\n";
        return;
    }
    else
    {
        cout << "\nQueue elements are: ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
}

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
