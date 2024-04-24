#include <iostream>
using namespace std;

const int maxSize = 5;
int deque[maxSize];
int front = -1, rear = -1;

void insertFront(int value);
void insertRear(int value);
void deleteFront();
void deleteRear();
void display();

int main()
{
    int choice, value;
    cout << "1.Insert Front\n";
    cout << "2.Insert Rear\n";
    cout << "3.Delete Front\n";
    cout << "4.Delete Rear\n";
    cout << "5.Display\n";
    cout << "6.Exit\n";

    do
    {
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the value to insert at front: ";
            cin >> value;
            insertFront(value);
            break;
        case 2:
            cout << "Enter the value to insert at rear: ";
            cin >> value;
            insertRear(value);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            display();
            break;
        case 6:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 6);

    return 0;
}

void insertFront(int value)
{
    if ((front == 0 && rear == maxSize - 1) || ((rear + 1) % maxSize == front))
    {
        cout << "\nDeque is full\n";
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
        deque[front] = value;
    }
    else if (front == 0)
    {
        front = maxSize - 1;
        deque[front] = value;
    }
    else
    {
        front--;
        deque[front] = value;
    }
}

void insertRear(int value)
{
    if ((front == 0 && rear == maxSize - 1) || ((rear + 1) % maxSize == front))
    {
        cout << "\nDeque is full\n";
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
        deque[rear] = value;
    }
    else
    {
        rear = (rear + 1) % maxSize;
        deque[rear] = value;
    }
}

void deleteFront()
{
    if (front == -1)
    {
        cout << "Deque Underflow\n";
        return;
    }
    cout << "Element deleted from front of deque is : " << deque[front] << "\n";
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == maxSize - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void deleteRear()
{
    if (front == -1)
    {
        cout << "Deque Underflow\n";
        return;
    }
    cout << "Element deleted from rear of deque is : " << deque[rear] << "\n";
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = maxSize - 1;
    }
    else
    {
        rear--;
    }
}

void display()
{
    if (front == -1)
    {
        cout << "\nDeque is Empty";
        return;
    }
    cout << "\nDeque elements are: ";
    if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
        {
            cout << deque[i] << " ";
        }
    }
    else
    {
        for (int i = front; i < maxSize; i++)
        {
            cout << deque[i] << " ";
        }
        for (int i = 0; i <= rear; i++)
        {
            cout << deque[i] << " ";
        }
    }
}
